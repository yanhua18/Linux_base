#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    int fd=open("./myfifo",O_WRONLY);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    while(1)
    {
        char buf[1024]={0};
        //用户自己写数据
        printf("->");
        fflush(stdout);
        read(0,buf,sizeof(buf)-1);
        write(fd,buf,strlen(buf));

    }
    close(fd);
    return 0;
}
