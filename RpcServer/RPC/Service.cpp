#include"Service.h"
#include"../Log.h"
#include<iostream>
using namespace std;
Service::Service(){

}

void Service::RegisterService(const std::string& function_name,RpcFun rpc_fun)
{
    if(rpc_fun != nullptr)
    {
        function_name_rpc_map[function_name] = rpc_fun;
    }
}

void Service::DetachService(const std::string& function_name)
{
    if(function_name_rpc_map.find(function_name) != function_name_rpc_map.end())
    {
        function_name_rpc_map.erase(function_name);
    }
}

bool Service::CallRpc(const std::string& function_name,const std::string& req,std::string& res,bool& keep_alive)
{
    if(function_name_rpc_map.find(function_name) != function_name_rpc_map.end())
    {
        return function_name_rpc_map[function_name](req,res,keep_alive);
    }
    return false;
}


bool Add(const std::string& req,std::string& res,bool& keep_alive)
{
    AddRequest add_request;
    AddRespone add_respone;
    add_request.ParseFromString(req);
    if(add_request.has_keepalive())
    {
        keep_alive = add_request.keepalive();
    }
    if(add_request.has_num1() && add_request.has_num2())
    {
        add_respone.set_resule(add_request.num1() + add_request.num2());
    }
    if(add_respone.has_resule())
    {
        res = add_respone.SerializeAsString();
        LOG<<"RPC Succeed!  RPC result:"<<to_string(add_respone.resule());
        return true;
    }
    return false;
}