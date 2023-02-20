#include <client.h>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

int main(int argc, char const* argv[])
{
    int ret;
    client *myClient = new client();
    ret = myClient->initialization();
    if(ret == EXIT_SUCCESS){
        printf("Client initialized success \n");

        for (int i = 0; i < 1000; i++)
        {
            sleep(1);
            char *chr1 = "Client send hello server";
            std::string s = std::to_string(i);
            char const *pchar = s.c_str();
            char* buffer = new char[strlen(chr1) + strlen(pchar) + 1 + 1];
            strcpy(buffer, chr1);
            strcat(buffer, " ");
            strcat(buffer, pchar);
            myClient->sentData(buffer);
            delete[] buffer;
        }  
    }

    delete myClient;
    return 0;
}