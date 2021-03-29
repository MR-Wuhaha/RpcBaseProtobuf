#ifndef RPC_CLIENT_H
#define RPC_CLIENT_H
#include"Channel.h"
#include"protoFile/add.pb.h"
#include<unordered_map>
#include<functional>
using namespace std;
class RpcClient : public Channel
{
    typedef function<void(const string&)> RpcRespone;
    public:
        RpcClient(const char* _ip_address,int _port,bool _keep_alive);
        int HandleEvent() override;

        //RPC call
        void Add(double num1,double num2);
    private:
        //RPC respone
        void Rpc_Add_Respone(const string& respone);

        bool keep_alive;
        unordered_map<string,RpcRespone> handle_rpc_respone;
};
#endif