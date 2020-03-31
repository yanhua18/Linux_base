#include<stdio.h>
#include"httplib.h"

using namespace httplib;
void func(const Request& req,Response& resp)
{
   resp.set_content("<html>hello bite</html>","123"); 
}
int main()
{
    Server svr;

    svr.Get("/",func);
    svr.listen("192.168.92.128",19998);
    return 0;
}
