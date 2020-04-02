#pragma once
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include<fstream>
#include"oj_log.hpp"
//实现一个切割字符串的函数
class StringTools
{
    public:
        static void Split(const std::string& input,const std::string& split_char,std::vector<std::string>* output)
        {
            boost::split(*output,input,boost::is_any_of(split_char),boost::token_compress_off);
        }
};

//实现文件操作的类
class FileOperater
{
    public:
        static int ReadDataFromFile(const std::string& filename,std::string* content)
        {
            std::ifstream file(filename.c_str());
            if(!file.is_open())
            {
                LOG(ERROR,"Open file failed! filename is");std::cout<<filename<<std::endl;
                return -1;
            }
            std::string line;
            while(std::getline(file,line))
            {
                *content+=line+"\n";
            }
            file.close();
            return 0;
        }
};
