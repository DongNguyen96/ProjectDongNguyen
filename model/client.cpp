#include <client.h>

using namespace std;

client::client(/* args */)
{
}

client::~client()
{
}

client::connection::connection() {}
client::connection::~connection() {}

client::try_connection::try_connection() {}
client::try_connection::~try_connection() {}

client::disconnection::disconnection() {}
client::disconnection::~disconnection() {}

void client::connection::receiveData(int newclientSocket) {

    // Receive data from the server
    char recvData[512];
    int iResult = recv(newclientSocket, recvData, 512, 0);
    if (iResult > 0) {
        recvData[iResult] = '\0';
        cout << "Data received: " << recvData << endl;
    }
    else if (iResult == 0) {
        cout << "Connection closed by server." << endl;
    }
    else {
        cerr << "Error receiving data" << endl;
    }
}
