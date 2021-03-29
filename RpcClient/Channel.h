#ifndef CHANNEL_H
#define CHANNEL_H
#include"otherFun.h"
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<memory>
#include<sys/epoll.h>
using namespace std;
class Channel;
class Epoll;
typedef shared_ptr<Channel> SP_channel;
class Channel : public enable_shared_from_this<Channel>
{
    friend class Epoll;
    public:
        Channel(const char* _ip_address,int _port);
        int ConnectServer();
        int GetFd();
        virtual int HandleConnect();
        virtual int HandleRead();
        virtual int HandleWrite();
        virtual int HandleEvent();
        virtual void handle_close();
        virtual ~Channel();
        friend int readn(int fd,char* buff,int length);
        friend int writen(int fd,char* buff,int length);
        friend int Connect(int fd,char* ip_addr,int port);
    protected:
        Epoll *attach_epoll;
        Epoll *accept_epoll;
        epoll_event epevent;//设置的事件
        uint32_t Revent;//产生的事件
        bool Connected;
        int fd;
        int port;
        char ip_address[16];
        char readbuff[4096];
        int read_length;
        int write_length;
        char writebuff[4096];
        int try_connect_times;
};
#endif