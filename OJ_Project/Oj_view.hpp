#pragma once
#include<ctemplate/template.h>
#include<string>
#include<vector>
#include"oj_model.hpp"
class oj_view
{
    public:
        //填充HTML页面，并将页面返回给调用
        static void ExpandAllQuestionshtml(std::string* html,std::vector<Questions>& ques)
        {
            //1，获取数据字典---将拿到的实体数据按照一定的顺序保存到内存中
            ctemplate::TemplateDictionary dict("all_questions");
            for(const auto& que:ques)
            {
                ctemplate::TemplateDictionary* section_dict = dict.AddSectionDictionary("question");
                section_dict->SetValue("id",que.id_);
                section_dict->SetValue("id",que.id_);
                section_dict->SetValue("name",que.name_);
                section_dict->SetValue("star",que.star_);
            }
            //2，获取模板类指针，加载预定义的HTML页面
            
            ctemplate::Template* t1=ctemplate::Template::GetTemplate("./template/all_questions.html",ctemplate::DO_NOT_STRIP);
            t1->Expand(html,&dict);

            //3，拿着模板类的指针，将数据字典中的数据更新到HTML页面的内存中
        }
};

