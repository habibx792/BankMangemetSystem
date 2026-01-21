#ifndef SystemMange_H
#define SystemMange_H

#include <string>
#include <iostream>
#include "dataHandle.h"
using namespace std;

class SystemMange
{
private:
    SystemMange()
    {
    }
    SystemMange(SystemMange &) = delete;
    SystemMange &operator=(SystemMange &) = delete;

protected:
    // member variables
public:
    static SystemMange &getInstance()
    {
        static SystemMange instance;
        return instance;
    }
    DataHandle &dt = DataHandle::GetInstance();
    // constructors
    void run()
    {
        cout << "========================== Welcome To Lazerus Bank ====================\n";

        cout
            << "Shutting off the System................. \n";
    }
};

#endif // SystemMange_H