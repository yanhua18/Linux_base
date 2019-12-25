#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    //对命名管道的操作和对文件的操作一样
    int fd=open("./myfifo",O_RDONLY);
    if(fd<0)
    {
        perror("resd open");
        return 1;
    }
    while(1)
    {
        char buf[1024]={0};
        ssize_t n=read(fd,buf,sizeof(buf)-1);
        if(n<0)
        {
            perror("read ");
            return 1;
        }
        if(n==0)
        {
            //对所有写端关闭，读端已经读完了
            
            return 0;
        }

        buf[n]='\0';
        printf("[read] %s\n",buf);
    }
    return 0;
}
