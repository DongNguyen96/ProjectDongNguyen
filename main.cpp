#include <iostream>
#include <server.h>
#include <client.h>

using namespace std;

int main() {
    int clientSocket{0};
    server::connection* my_connectionServer = new server::connection();
    client::connection* my_connectionClient = new client::connection();

    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Error creating socket" << endl;
    }else{
        cerr << "created socket is " << clientSocket << endl; 
    }

    my_connectionServer->sendingData(clientSocket);
    my_connectionClient->receiveData(clientSocket);


    // Clean up
    close(clientSocket);

    delete my_connectionServer;
    delete my_connectionClient;

    return 0;
}
