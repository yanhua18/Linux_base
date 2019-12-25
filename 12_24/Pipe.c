#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{

    //int fd[2];
    //int ret=pipe(fd);
    //if(ret<0)
    //{
    //    perror("pipe");//文件描述符已经用完了，管道使用完成之后需要及时关闭文件描述符
    //    return 1;
    //}
    //ret=fork();
    //if(ret>0)
    //{
    //    //father
    //    //写数据
    //    char buf[1024]="hehe";
    //    write(fd[1],buf,strlen(buf));
    //    char buf_output[1024]={0};
    //    read(fd[0],buf_output,sizeof(buf_output));
    //    printf("father read %s\n",buf_output);
    //}
    //else if(ret==0j)
    //{
    //    //child
    //    //读数据
    //    char buf_output[1024]={0};
    //    read(fd[0],buf_output,sizeof(buf_output));
    //    printf("child read %s\n",buf_output);
    //}
    //else
    //{
    //    perror("fork");
    //}




    //char buf[1024]="hehe";
    //write(fd[1],buf,strlen(buf));
    //char buf_output[1024]={0};
    //ssize_t n=read(fd[0],buf_output,sizeof(buf_output)-1);
    //buf_output[n]='\0';
    //printf("%s",buf_output);
    close(fd[0]);//用来读数据
    close(fd[1]);//用来写数据
    return 0;
}
