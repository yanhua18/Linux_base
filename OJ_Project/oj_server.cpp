#include"httplib.h"

int main()
{
    using namespace httplib;
    Server svr;
    //1,获取试题的信息（从文件中获取）
    svr.Get("/all_questions",[](const Request& req , Response& resp)
            {
            resp.set_content("<html>xxxx</html>","text/html");
            });
    svr.listen("0.0.0.0",18888);
    return 0;
}
