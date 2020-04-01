#include"httplib.h"
#include"oj_model.hpp"
#include<stdio.h>
#include<string.h>
#include<string>
#include"Oj_view.hpp"
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

//            char buf[10240]={'\0'};
//           printf("%d\n",ques.size());
//           if(ques.size()==1)
//           {
//           snprintf(buf,sizeof(buf)-1,"<html>%s.%s %s</html>",ques[0].id_.c_str(),ques[0].name_.c_str(),ques[0].star_.c_str());
//           }
//           std::string html;
//           html.assign(buf,strlen(buf));
            
            std::string html;
            oj_view::ExpandAllQuestionshtml(&html,ques);
            resp.set_content(html,"text/html;charset=UTF-8");
            });
    //正则表达式
    //    \b单词的分界
    //    * 匹配任意字符串
    //    \d 匹配一个数字
    //    源码转义：特殊字符按照特殊字符字面源码来进行编译 R"(stdr)"
    svr.Get(R"(/question/\d)",[&ojmode](const Request& req , Response& resp)
            {
            std::string html="1";
            resp.set_content(html,"text/html;charset=UTF-8");
            });

    svr.listen("0.0.0.0",18888);
    return 0;
}
