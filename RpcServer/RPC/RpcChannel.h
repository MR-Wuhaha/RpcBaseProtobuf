#ifndef RPC_CHANNEL_H
#define RPC_CHANNEL_H
#include"../channel.h"
#include"Service.h"
class RpcChannel : public channel
{
    public:
        static Service service;
        RpcChannel(int _fd,uint32_t _Sevent,Handle _read,Handle _write,TimeRound<channel>* _time_round);
        virtual void Add_New_Connect(int fd);
        virtual int handle_event();
        void HandleRpc();
        ~RpcChannel();
    private:
        bool Keep_Alive;
};
#endif