#include"RpcChannel.h"
#include"../Epoll.h"
#include"../Log.h"
#include<string.h>

Service RpcChannel::service;
RpcChannel::RpcChannel(int _fd,uint32_t _Sevent,Handle _read,Handle _write,TimeRound<channel>* _time_round):
channel(_fd,_Sevent,_read,_write,_time_round)
{
    Keep_Alive = false;
}

void RpcChannel::Add_New_Connect(int fd)
{
    SP_channel conn_socket(new RpcChannel(fd,EPOLLIN | EPOLLET,readn,writen,time_round));
    if(attach_epoll != nullptr)
        attach_epoll->Epoll_Add(conn_socket,false);
}

int RpcChannel::handle_event()
{
    if(Revent & EPOLLIN)
    {
        HandleRead();
        if(accept_epoll == nullptr)
        {
            HandleRpc();
            SeparateTimer();
            if(time_round != nullptr && Keep_Alive)
            {
                std::shared_ptr<TimeRoundItem<channel>> sp_time_round_item(new TimeRoundItem<channel>(5,bind(&RpcChannel::Close,shared_from_this().get()),shared_from_this()));
                wp_time_round_item = std::weak_ptr<TimeRoundItem<channel>>(sp_time_round_item);
                SP_TimeRoundItemNode<channel>* sp_time_round_item_node = new SP_TimeRoundItemNode<channel>(sp_time_round_item);
                time_round->AddTimeRoundItemNode(sp_time_round_item_node);
            }
        }
    }
    else if(Revent & EPOLLOUT)
    {
        HandleWrite();
    }
    Revent = 0;
    return 0;
}

RpcChannel::~RpcChannel()
{

}

void RpcChannel::HandleRpc()
{
    int pos = 0;
    string function_name = "";
    while(pos < read_length && read_buff[pos] != ' ')
    {
        function_name += read_buff[pos];
        pos++;
    }
    if(pos == 0)
    {
        LOG<<"RPC error!";
        return;
    }
    LOG<<"RPC request method : "<<function_name;
    string request = string(read_buff,read_length).substr(pos+1,read_length-pos-1);
    string respone;
    if(service.CallRpc(function_name,request,respone,Keep_Alive))
    {
        respone = function_name + " " + respone;
        memcpy(write_buff,respone.c_str(),respone.length());
        write_length = respone.length();
    }
    else
    {
        memcpy(write_buff,"RPC Error",9);
        write_length = 9;
    }
    HandleWrite();
}