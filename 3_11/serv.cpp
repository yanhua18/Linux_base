#include"udpserver.hpp"

//通过命令行参数来获取这两个信息 
int main(int argc,char*argv[])
{
   if(argc!=3)
   {
       printf("./svr [ip] [port]");
       return 0;
   }

   std::string ip=argv[1];
   uint16_t port=atoi(argv[2]);

   Udpsvr us;
   if(!us.CreatSock())
   {
       return 0;
   }
   if(!us.Bind(ip,port))
   {
       return 0;
   }
   while(1)
   {
       std::string buf;
       struct sockaddr_in peer_addr;
       us.Recv(buf,&peer_addr);

       printf("client say:[%s]\n",buf.c_str());
       printf("server say:");
       fflush(stdout);

       std::cin>>buf;

       us.Send(buf,&peer_addr);
   }
   us.Close();
   return 0;
}


