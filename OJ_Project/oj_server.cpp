#include"httplib.h"

int main()
{
    //使用httplib.h的时候，需要使用httplib提供的命名空间
    using namespace httplib;
    Server svr;
    svr.Get("/aaa",[](const Request& req,Response& resp)
            {
            printf("i get menthens\n");
            });
    svr.listen("0.0.0.0",19999);
    return 0;
}
