#include <iostream>
#include <windows.h>
#include "customer.h"
void clearScrean()
{
#ifndef _WIN32
    system("c");
#else
    system("clear");
#endif
}
using namespace std;
int main()
{
    clearScrean();
    Customer c("haib", "wali", 22, 1);
    cout << "hellp World \n";
    cout<<"Here the Main Programme Excutes "<<endl;
    return 0;
}
