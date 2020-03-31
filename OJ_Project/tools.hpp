#pragma once
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
//实现一个切割字符串的函数
class StringTools
{
    public:
        static void Split(const std::string& input,const std::string& split_char,std::vector<std::string>* output)
        {
            boost::split(*output,input,boost::is_any_of(split_char),boost::token_compress_off);
        }
};
