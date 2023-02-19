#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "managementTheard.hpp"
 
int main(int argc, char *argv[])
{
    managementTheard p;

    p.thread_send();
    p.thread_received();
    
    return 0;
}