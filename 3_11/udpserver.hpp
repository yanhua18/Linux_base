#include<unistd.h>
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
class Udpsvr
{
    public:
        Udpsvr()
        {
            Sock_=-1;
        }
        ~Udpsvr()
        {}
        //创建套接字
        bool CreatSock()
        {
            Sock_=socket(AF_INET,SOCK_DGRAM,17);
            if(Sock_<0)
            {
                perror("socket");
                return false;
            }
            return true;
        }
        bool Bind(std::string& ip,uint16_t port)
        {
            struct sockaddr_in addr;
            addr.sin_family=AF_INET;
            addr.sin_port=htons(port);
            addr.sin_addr.s_addr=inet_addr(ip.c_str());
            int ret=bind(Sock_,(struct sockaddr*)& addr,sizeof(addr));
            if(ret<0)
            {
                perror("bind");
                return false;
            }
            return true;
        }

        
        //发送数据
        
        bool Send(std::string& buf,struct sockaddr_in* destaddr)
        {
            //在计算addrlen时，不能直接求sizeof(destaddr),因为destaddr是一个指针
            int sendsize=sendto(Sock_,buf.c_str(),buf.size(),0,(struct sockaddr*)&destaddr,sizeof(struct sockaddr_in));
            if(sendsize<0)
            {
                perror("sendto  is error");
                return false;
            }
            return true;
        }
        
        //接收数据
        bool Recv(std::string& buf,struct sockaddr_in* srcaddr)
        {
            char tmp[1024]={0};
            socklen_t socklen=sizeof(struct sockaddr_in);
            int recvsize= recvfrom(Sock_,tmp,sizeof(tmp)-1,0,(struct sockaddr*)srcaddr,&socklen);
            if(recvsize<0)
            {
                perror("recvfrom");
                return false;
            }
            buf.assign(tmp,recvsize);
            return true;
        }
        
        void Close()
        {
            close(Sock_);
            Sock_=-1;
        }
    private:
        int Sock_;
};
