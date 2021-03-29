#include"RpcClient.h"
RpcClient::RpcClient(const char* _ip_address,int _port,bool _keep_alive):
Channel(_ip_address,_port),keep_alive(_keep_alive)
{
    handle_rpc_respone["Add"] = bind(&RpcClient::Rpc_Add_Respone,this,std::placeholders::_1);
}

int RpcClient::HandleEvent()
{
    if(Connected == false)
    {
        return HandleConnect();
    }
    else
    {
        if(Revent & EPOLLIN)
        {
            Revent = 0;
            if(HandleRead() == 0)
            {
                handle_close();
                return 0;
            }
            int pos = 0;
            string function_name = "";
            while(pos < read_length && readbuff[pos] != ' ')
            {
                function_name += readbuff[pos++];
            }
            if(handle_rpc_respone.count(function_name) != 0)
            {
                string respone = string(readbuff+pos+1,read_length - pos -1);
                handle_rpc_respone[function_name](respone);
            }
            else
            {
                cerr<<"Rpc Result Error"<<endl;
            }
        }
        else if(Revent & EPOLLOUT)
        {
            Revent = 0;
            if(HandleWrite() == 0)
            {
                handle_close();
                return 0;
            }
        }
        Revent = 0;
        return 0;
    }
}
//RPC Call
void RpcClient::Add(double num1,double num2)
{
    if(Connected == true)
    {
        AddRequest addrequest;
        AddRespone addrespone;
        addrequest.set_num1(num1);
        addrequest.set_num2(num2);
        addrequest.set_keepalive(keep_alive);
        string send_str = addrequest.SerializeAsString();
        send_str = "Add " + send_str;
        write_length = send_str.length();
        memcpy(writebuff,send_str.c_str(),send_str.length());
        if(HandleWrite() == 0)
        {
            handle_close();
        }
    }
    else
    {
        cerr<<"Socket Do Not Connect To Any Server!"<<endl;
    }
}

//RPC respone
void RpcClient::Rpc_Add_Respone(const string& respone)
{
    AddRespone addrespone;
    addrespone.ParseFromString(respone);
    if(addrespone.has_resule())
    {
        cout<<"RPC Resule : "<<addrespone.resule()<<endl;
    }
}