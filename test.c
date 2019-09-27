#include<stdio.h>
#include<unistd.h>
//命令行版本的进度条程序
int main()
{
  const char * label="/~\\|";
  char buffer[1024]={0};
  int i=0;
  for(;i<100;i++)
  {
    buffer[i]='#';
    printf("[%d%%][%c][%s]\r",i,label[i%4],buffer);
    fflush(stdout);
    usleep(500*1000);
  }
  
  return 0;
}
