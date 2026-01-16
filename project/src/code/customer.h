#define _HAS_STD_BYTE 0
#ifndef customre_H
#define customre_H
#include <iostream>
#include <string>
#include "dataHandle.h"
#include "person.h"
using namespace std;
DataHandle &d = DataHandle::GetInstance();
class Customer:public Person
{
    private:

    protected:
    bool hasAtm;
    public:

    Customer():Person()
    {

    }
    


};

#endif