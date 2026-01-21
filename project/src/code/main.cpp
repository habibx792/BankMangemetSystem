#include <iostream>
#include <windows.h>
#include "customer.h"
#include "dataHandle.h"
#include "system.h"
void clearScrean()
{
#ifndef _WIN32
    system("c");
#else
    system("clear");
#endif
}
using namespace std;
void playLogin()
{
    cout << "Welcome To Bank \n";
    cout << "Please Wait a while we are Loading Data....\n";
}
int main()
{

    SystemMange &systemy = SystemMange::getInstance();
    systemy.run();
    return 0;
}
