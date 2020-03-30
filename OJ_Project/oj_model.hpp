#pragma once
#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>

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
        bool GetAllQuestions();
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
                

            }
        }
    private:
        std::unordered_map<std::string ,Questions> model_map_;
};
