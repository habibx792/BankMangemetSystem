#include <iostream>
#include <windows.h>
#include "customer.h"
#include "dataHandle.h"
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

    // clearScrean();
    // system start a login sound should play
    playLogin();

    Customer c("haib", "wali", 22, 1);
    cout << "hellp World \n";
    return 0;
}
