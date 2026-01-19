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
    DataHandle &dt = DataHandle::GetInstance();
    cout << dt.getRandomNoStr() << endl;
    cout << dt.getRandomNumber() << endl;
    cout << "Generating otp to prevent hacking.... \n";
    cout << dt.getOtp() << endl;
    // dt.printSystemInfo();
    cout
        << "hellp World \n";
    return 0;
}
