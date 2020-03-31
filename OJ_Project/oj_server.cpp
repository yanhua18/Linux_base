#include"httplib.h"
#include"oj_model.hpp"
#include<stdio.h>
#include<string.h>
#include<string>
int main()
{
    using namespace httplib;
    Server svr;
    //1,获取试题的信息（从文件中获取）
    oj_Model ojmode;
    svr.Get("/all_questions",[&ojmode](const Request& req , Response& resp)
            {
            std::vector<Questions> ques;
            ojmode.GetAllQuestions(&ques);
            char buf[10240]={'\0'};
            printf("%d\n",ques.size());
            if(ques.size()==1)
            {
            snprintf(buf,sizeof(buf)-1,"<html>%s.%s %s</html>",ques[0].id_.c_str(),ques[0].name_.c_str(),ques[0].star_.c_str());
            }
            std::string html;
            html.assign(buf,strlen(buf));
            


            resp.set_content(html,"text/html");
            });
    svr.listen("0.0.0.0",18888);
    return 0;
}
