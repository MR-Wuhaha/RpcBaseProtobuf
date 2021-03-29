#include"Channel.h"
#include"Epoll.h"
Channel::Channel(const char* _ip_address,int _port) : port(_port),attach_epoll(nullptr),accept_epoll(nullptr),Connected(false),try_connect_times(5),
read_length(0),write_length(0)
{
    fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd < 0 || _ip_address == nullptr || strlen(_ip_address) > 16)
    {
        cerr<<"Initialing Socket Error!"<<endl;
        return;
    }
    set_noblock(fd);
    memset(ip_address,0,sizeof(ip_address));
    memset(readbuff,0,sizeof(readbuff));
    memset(writebuff,0,sizeof(writebuff));
    int pos = 0;
    while(_ip_address[pos] != '\0')
    {
        ip_address[pos] = _ip_address[pos];
        pos++;
    }
    ip_address[pos] = '\0';
    epevent.events =  EPOLLIN | EPOLLET | EPOLLOUT;
    epevent.data.fd = fd;
    Revent = 0;
}

int Channel::ConnectServer()
{
    int flag = Connect(fd,ip_address,port);
    if(flag == 0)
    {
        cout<<"Connect Succeed!"<<endl;
        Connected = true;
        return 0;
    }
    else if(flag == -1)
    {
        handle_close();
        return -1;
    }
    return flag;
}

int Channel::GetFd()
{
    return fd;
}

int Channel::HandleConnect()
{
    if(Revent & EPOLLIN)
    {
        Revent = 0;
        if(try_connect_times-- <= 0)
        {
            cerr<<"Try Times Out, Connect Fail!"<<endl;
            handle_close();
            return -1;
        }
        ConnectServer();
        return 1;
    }
    if(Revent & EPOLLOUT)
    {
        Revent = 0;
        Connected = true;
        epevent.events = EPOLLIN | EPOLLET;
        attach_epoll->Epoll_Mod(shared_from_this());
        return 0;
    }
    return 1;
}

int Channel::HandleRead()
{
    read_length = readn(fd,readbuff,sizeof(readbuff));
    return read_length;
}

int Channel::HandleWrite()
{
    int wlen = writen(fd,writebuff,write_length);
    if(wlen > 0)
    {
        if(wlen != write_length)
        {
            memcpy(writebuff,writebuff + (write_length - wlen),wlen);
        }
        write_length = wlen;
        epevent.events = EPOLLIN | EPOLLOUT | EPOLLET;
        attach_epoll->Epoll_Mod(shared_from_this());
    }
    else if(wlen == -1)
    {
        epevent.events = EPOLLIN | EPOLLET;
        attach_epoll->Epoll_Mod(shared_from_this());
    }
    return wlen;
}

int Channel::HandleEvent()
{
    if(Connected == false)
    {
        return HandleConnect();
    }
    return 0;
}

void Channel::handle_close()
{
    if(attach_epoll != nullptr)
        attach_epoll->Epoll_Del(fd);
    close(fd);
    printf("Close Client Fd[%d]\n",fd);
}

Channel::~Channel()
{

}

