#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
// #include <convert.h>

class server 
{
private:
    int myclientSocket;

public:
    server();
    ~server();

    class connection
    {
    private:
    public:
        connection();
        ~connection();
        void sendingData(int newclientSocket);
    };

    class try_connection
    {
    private:
    public:
        try_connection();
        ~try_connection();

        friend server;
    };
    
    class disconnection
    {
    private:
    public:
        disconnection();
        ~disconnection();

        friend server;
    };
};

