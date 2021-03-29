#include<iostream>
#include"Epoll.h"
#include"RpcClient.h"
#include<vector>
using namespace std;
int main()
{
    Epoll m_epoll(10);
    SP_channel rpc_client(new RpcClient("0.0.0.0",80,true));
    m_epoll.Epoll_Add(rpc_client,false);
    rpc_client->ConnectServer();
    while(1)
    {
        vector<SP_channel> results = m_epoll.Poll();
        for(int i = 0;i<results.size();i++)
        {
            results[i]->HandleEvent();
            RpcClient* ptr = dynamic_cast<RpcClient*>(results[i].get());
            if(ptr != nullptr)
            {
                ptr->Add(2.222,2.333);
            }
        }
        sleep(3);
    }
    return 0;
}