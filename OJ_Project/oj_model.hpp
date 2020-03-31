#pragma once
#include<iostream>
#include<unistd.h>
#include<unordered_map>
#include<string>
#include<fstream>
#include<algorithm>
#include"tools.hpp"

typedef struct Questions
{
    std::string id_;
    std::string name_;
    std::string path_;
    std::string star_;
}QUES;
class oj_Model
{
    public:
        oj_Model()
        {
            LoadQuestions("./config_oj.cfg");
        }
        bool GetAllQuestions(std::vector<Questions>* ques)
        {
            for(const auto& kv:model_map_)
            {
                ques->push_back(kv.second);
            }
            std::sort(ques->begin(),ques->end(),[](const Questions& l,const Questions& r)
                    {
                    return atoi(l.id_.c_str()) < std::atoi(r.id_.c_str());
                    });
            return true;
        }
    private:
        bool LoadQuestions(const std::string& configfile_path)
        {
            //使用C++中的文件流来加载文件，获取文件中的内容
            std::ifstream file(configfile_path.c_str());
            if(!file.is_open())
            {
                return false;
            }

            std::string line;
            while(std::getline(file,line))
            {
                //需要切割字符串，并将其保存到unordered_map中
                std::vector<std::string> vec;
                StringTools::Split(line,"\t",&vec);
                if(vec.size()!=4)
                {
                    continue;
                }
                Questions ques;
                ques.id_=vec[0];
                ques.name_=vec[1];
                ques.path_=vec[2];
                ques.star_=vec[3];
                model_map_[ques.id_]=ques;
            }
            file.close();
        }
    private:
        std::unordered_map<std::string ,Questions> model_map_;
};
