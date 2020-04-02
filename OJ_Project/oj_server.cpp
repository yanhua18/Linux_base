#include"httplib.h"
#include"oj_model.hpp"
#include<stdio.h>
#include<string.h>
#include<string>
#include"Oj_view.hpp"
#include"oj_log.hpp"
int main()
{
    using namespace httplib;
    Server svr;
    //1,获取试题的信息（从文件中获取）
    oj_Model ojmode;
    svr.Get("/all_questions",[&ojmode](const Request& req , Response& resp)
            {
            std::vector<Question> ques;
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
            //LOG(INFO,html);
            resp.set_content(html,"text/html;charset=UTF-8");
            });
    //正则表达式
    //    \b单词的分界
    //    * 匹配任意字符串
    //    \d 匹配一个数字
    //    源码转义：特殊字符按照特殊字符字面源码来进行编译 R"(stdr)"
    svr.Get(R"(/question/(\d+))",[&ojmode](const Request& req , Response& resp)
            {
            //1,去实体模块去查找对应题号的具体题目信息（map当中）
            std::string desc;
            std::string header;
            //从querystr中获取id

            LOG(INFO,"req.matches");std::cout<<req.matches[0]<<":"<<req.matches[1]<<std::endl;
            //2,在题目地址的路径下去加载题目的具体描述信息
            struct Question ques;
            ojmode.GetOneQuestion(req.matches[1].str(),&desc,&header,&ques);
           //3,进行组织，并返回给浏览器             
            std::string html;
            oj_view::ExpandOneQuestion(ques,desc,header,&html);

            resp.set_content(html,"text/html;charset=UTF-8");
            });

    LOG(INFO,"listen for 0.0.0.0:19999");std::cout<<std::endl;
    LOG(INFO,"Server ready");std::cout<<std::endl;
    //listen函数会阻塞
    svr.listen("0.0.0.0",18888);
    return 0;
}
