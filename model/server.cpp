#include <server.h>

using namespace std;

server::server() {}
server::~server() {}

server::connection::connection() {}
server::connection::~connection() {}

server::try_connection::try_connection() {}
server::try_connection::~try_connection() {}

server::disconnection::disconnection() {}
server::disconnection::~disconnection() {}

/// @brief 
/// @param newclientSocket 
void server::connection::sendingData(int newclientSocket) {
     // Set up the server address and port
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(27015);

    cerr << "connection socket is " << newclientSocket << endl;

    // Connect to the server
    int iResult = connect(newclientSocket, (struct sockaddr*)&serverAddress,
     sizeof(serverAddress));
    if (iResult == -1) {
        cerr << "Error connecting to server" << endl;
    }


    // Send data to the server
    const char* sendData = "Hello, server!";
    iResult = send(newclientSocket, sendData, strlen(sendData), 0);
    if (iResult == -1) {
        cerr << "Error sending data" << endl;
    }

    cout << "Data sent: " << sendData << endl;
}
