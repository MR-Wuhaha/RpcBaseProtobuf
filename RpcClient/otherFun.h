#ifndef _OTHERFUN
#define _OTHERFUN
#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<iostream>
#include<cstring>
#include<memory>
#include<assert.h>
int Connect(int fd,char* ip_address,int port);
int readn(int _channel,char *buff,int length);
int writen(int _channel,char *buff,int length);
int set_noblock(int);
#endif