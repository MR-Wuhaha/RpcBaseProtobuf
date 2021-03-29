#include"otherFun.h"
using namespace std;

int Connect(int fd,char* ip_address,int port)
{
    if(fd < 0)
    {
        return 0;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    assert(inet_aton(ip_address,&server_addr.sin_addr));
    while(1)
    {
        int flag = connect(fd,(struct sockaddr*)&server_addr,sizeof(server_addr));
        if(flag == 0)
        {
            return 0;
        }
        else if(flag == -1)
        {
            if(errno == EINTR)
            {
                continue;
            }
            else if(errno != EINPROGRESS)
            {
                cerr<<"Connect Fail!"<<endl;
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
}

int readn(int fd,char *buff,int length)
{
    int read_len = 0;
    memset(buff,0,length);
    int max_length = length;
    while(length > 0)
    {
        int rlen = recv(fd,buff,length,0);
        if(rlen < 0)
        {
            if(errno == EAGAIN)
            {
                break;
            }
            else if(errno == EINTR)
            {
                continue;
            }
        }
        else if(rlen > 0)
        {
            length = length - rlen;
            buff = buff + rlen;
            read_len += rlen;
        }
        else
        {
            return 0;
        }
    }
    if(read_len == 0)
    {
        return -1;
    }
    return read_len;
}
int writen(int fd,char *buff,int length)
{
    while(length > 0)
    {
        int wlen = send(fd,buff,length,0);
        if(wlen < 0)
        {
            if(errno == EAGAIN)
            {
                break;
            }
            else if(errno == EINTR)
            {
                continue;
            }
        }
        else if(wlen > 0)
        {
            length = length - wlen;
            buff = buff + wlen;
        }
        else
        {
            return 0;
        }
    }
    //cout<<"send to client:"<<_channel->fd<<" success!"<<endl;
    //delete (char*)_channel->epevent.data.ptr;
    //_channel->epevent.data.ptr = NULL;
    if(length == 0)
    {
        return -1;
    }
    return length;
}
int set_noblock(int sockfd)
{
    if(sockfd < 0)
    {
        cout<<"sockfd is invailed"<<endl;
        return -1;
    }
    int flags = fcntl(sockfd,F_GETFL,0);
    fcntl(sockfd,F_SETFL,flags | O_NONBLOCK);
    return 1;
}