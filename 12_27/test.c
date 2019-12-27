#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
void MyHandler(int sig)
{
    (void) sig;
    printf("child exit\n");
    while(1)
    {
        int ret = waitpid(-1,NULL,WNOHANG);
        if(ret>0)
        {
            //这就继续执行循环
        }
        else
        {
            //退出循环
            break;
        }
    }
}
int main()
{
    signal(SIGCHLD,MyHandler);
    for(int i=20;i<20;i++)
    {
        pid_t ret=fork();
        if(ret==0)
        {
            printf("child pid %d\n",getpid());
            exit(0);
        }
    }
    while(1)
    {
        sleep(1);
    }
    return 0;
}
