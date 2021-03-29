#ifndef SERVICE_H
#define SERVICE_H
#include"protoFile/add.pb.h"
#include<functional>
#include<unordered_map>
class Service
{
    typedef std::function<bool(const std::string&,std::string&,bool&)> RpcFun;
    public:
        Service();
        void RegisterService(const std::string& function_name,RpcFun rpc_fun);
        void DetachService(const std::string& function_name);
        bool CallRpc(const std::string& function_name,const std::string& req,std::string& res,bool& keep_alive);
    private:
        Service(const Service&);
        Service& operator=(const Service&);

        std::unordered_map<std::string,RpcFun> function_name_rpc_map;
};
//参数：请求输入，输出应答，输出连接状态  返回RPC 调用结果是否成功
bool Add(const std::string& req,std::string& res,bool& keep_alive);
#endif


