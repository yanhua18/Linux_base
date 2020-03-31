#include"httplib.h"
#include"oj_model.hpp"
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
            resp.set_content("" ,"text/html");
            });
    svr.listen("0.0.0.0",18888);
    return 0;
}
