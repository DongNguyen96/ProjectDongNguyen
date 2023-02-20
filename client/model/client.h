#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
  

class client
{
private:
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    // char* message = "Hello from client";
    char buffer[1024] = { 0 };
public:
    client(/* args */);
    ~client();
    /// @brief 
    /// @return 
    int initialization();
    void sentData(const char* message);
    int listenServer();
};


