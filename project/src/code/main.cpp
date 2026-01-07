#include <iostream>
#include <windows.h>
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
    
    cout << "hellp World \n";
    clearScrean();
    return 0;
}