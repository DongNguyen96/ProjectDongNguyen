#include <server.h>

server::server(/* args */)
{
}

server::~server()
{
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
}

/// @brief 
int server::initialization()
{
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
        // exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        return EXIT_FAILURE;
        // exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        // exit(EXIT_FAILURE);
        return EXIT_FAILURE;
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        // exit(EXIT_FAILURE);
        return EXIT_FAILURE;
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        // exit(EXIT_FAILURE);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void server::sentData(const char *message)
{
    send(new_socket, message, strlen(message), 0);
}

int server::listenClient()
{
    valread = read(new_socket, buffer, 1024);

    if(buffer != "")
    {
        printf("%s\n", buffer);
        return EXIT_SUCCESS;
    }else{
        printf("nothing \n");
        return EXIT_FAILURE;
    }
}
