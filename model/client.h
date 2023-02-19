#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
// #include <convert.h>

class client 
{
private:
    int myclientSocket;

public:
    client();
    ~client();

    class connection
    {
    private:
    public:
        connection();
        ~connection();
        void receiveData(int newclientSocket);
        friend client;
    };

    class try_connection
    {
    private:
    public:
        try_connection();
        ~try_connection();

        friend client;
    };
    
    class disconnection
    {
    private:
    public:
        disconnection();
        ~disconnection();

        friend client;
    };
};




