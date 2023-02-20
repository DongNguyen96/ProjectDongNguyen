#include <server.h>

int main(int argc, char const* argv[])
{
    int ret; 
    server *Myserver = new server();
    ret = Myserver->initialization();

    if(ret == EXIT_SUCCESS){
        printf("Server initialized success \n");
        while (1)
        {     
            ret = Myserver->listenClient();
            if(ret == EXIT_SUCCESS){
                Myserver->sentData("the server has received your data request!"); 
            }
        }
    }


    delete Myserver;
    return 0;
}