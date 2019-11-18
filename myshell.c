#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int Split(char input[],char* output[])
{
    //input表示待切分的命令；output表示切分结果
    //返回值表示output中包含了几个有效元素
    //借助strtok来实现
    char* p=strtok(input," ");
    int i=0;
    while(p!=NULL)
    {
        output[i]=p;
        ++i;
        p=strtok(NULL," ");
    }
    output[i]=NULL;//这个操作比较容易遗忘
}

void CreateProcess(char* argv[],int n)
{
    (void)n;
    //1,创建子进程
    pid_t ret=fork();
    //父进程进行进程等待，子进程进行程序替换
    if(ret>0)
    {
        wait(NULL);
    }else if(ret==0)
    {
        ret=execvp(argv[0],argv);
            perror("exec");
            exit(0);
    }
    else
    {
        perror("fork");
    }
}
int main()
{
    while(1)
    {
        //1,打印提示符
        printf("[heqing@home]");
        fflush(stdout);
        //2,用户输入一个指令
        char command[1024]={0};
        gets(command);//一次读一行数据
        //3,解析指令，把要执行那个程序识别出来
        //哪些命令行参数识别出来（字符串切分）
        char* argv[1024];
        int n=Split(command,argv);
        //4,创建子进程并进行程序替换
       CreateProcess(argv,n);

    }
}
