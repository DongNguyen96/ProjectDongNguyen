#include <client.h>


client::client(/* args */)
{
}

client::~client()
{
    //closing the connected socket
    close(client_fd);
}

int client::initialization()
{
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return EXIT_FAILURE;
    }
  
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

/// @brief 
/// @param message 
void client::sentData(const char *message)
{
    send(client_fd, message, strlen(message), 0);
    valread = read(client_fd, buffer, 1024);
    printf("%s\n", buffer);
}

int client::listenServer()
{
    valread = read(client_fd, buffer, 1024);

    if(buffer != "")
    {
        printf("%s\n", buffer);
        return EXIT_SUCCESS;
    }else{
        printf("nothing \n");
        return EXIT_FAILURE;
    }
}
