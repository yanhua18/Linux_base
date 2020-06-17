#pragma once 
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<string>
#include<json/json.h>
#include"oj_log.hpp"
class Compiler
{
    public:
        //有可能浏览器对不同的题目提交的数据是不同的
        //code="xxxx"
        //code="xxx"&stdin="xxx"
        static void CompileAndRun(Json::Value Req,Json::Value Resp)
        {
            //1,判空
            if(Req["code"].empty())
            {
                LOG(ERROR,"要求的代码为空！");
                std::cout<<std::endl;
                return;
            }
            //2,将代码写到文件当中去
            //文件名称进行约定 tmp_时间戳.cpp
            std::string code=Req["code"].asString();
            std::string tmp_filename=WriteTmpFile(code);
            if(tmp_filename=="")
            {
                LOG(ERROR,"Write Source failed");
                return;
            }
            //3,编译
            if(!Compile())
            {

            }
            //4，运行
            if(!Run())
            {

            }
            //5，构造响应

        }
    private:
        static std::string WriteTmpFile(const std::string& code)
        {
            //1,组织文件的名称，组织文件的前缀名称，用来区分源码文件，可执行文件是.一组数据
            std::string tmp_filename="tmp_"+std::to_string(LogTime::GetTimeStamp());
            //2,写文件
            int ret= FileOper::WriteDataToFile(SrcPath(tmp_filename),code);
            if(ret<0)
            {
                LOG(ERROR,"write code to source fail");
                return "";
            }
            return tmp_filename;
        }
        static std::string SrcPath(const std::string& filename)
        {
           return "./tmp_files"+filename+".cpp";
        }

        static std::string ExePath(const std::string& filename)
        {
           return "./tmp_files"+filename+".executable";
        }

        static std::string ErrorPath(const std::string& filename)
        {
           return "./tmp_files"+filename+".err";
        }

        static bool Compile(const std::string& filename)
        {
            //1,构造编译命令-->g++ src -o [exec] -std=c++11
            
            const int commandcount=20;
            char buf[commandcount][50]={{0}};
            char* Command[commandcount]={0};
            for(int i=0;i<commandcount;i++)
            {
                Command[i]=buf[i];
            }
            snprintf(Command[0],49,"%s","g++");
            snprintf(Command[1],49,"%s",SrcPath(filename).c_str());
            snprintf(Command[2],49,"%s","-o");
            snprintf(Command[3],49,"%s",ExePath(filename).c_str());
            snprintf(Command[4],49,"%s","-std=c++11");
            //2,创建子进程
            //2.1父进程-->等待子进程退出
            //2.2子进程-->进程程序替换--->g++
            int pid = fork();
            if(pid<0)
            {
                LOG(ERROR,"创建子进程失败！！！！");
                return false;
            }
            else if(pid==0)
            {
                //child
                int fd=open(ErrorPath(filename).c_str(),O_CREAT|O_RDWR,0664);
                //重定向
                dup2(fd,2);
                //程序替换
                execvp(Command[0],Command);
                exit(0);
            }
            else
            {
                //father
                waitpid(pid,NULL,0);
            }
            //3,验证是否生成可执行程序
            
        }

        static bool Run()
        {

        }
};
