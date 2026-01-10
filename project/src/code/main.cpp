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
int main()
{
    DataHandle &d=DataHandle::GetInstance();
    // clearScrean();
    cout<<d.captilize("helAl")<<endl;
    // Customer c("haib", "wali", 22, 1);
    // cout << "hellp World \n";
    // cout<<"I it time to git pull --rebase";
    // cout<<"Here the Main Programme Excutes "<<endl;
    return 0;
}
