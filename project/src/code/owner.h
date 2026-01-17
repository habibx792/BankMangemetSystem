#ifndef Owner_H
#define Owner_H

#include <string>
#include <iostream>
#include "person.h"
using namespace std;

class Owner:public Person {
private:
protected:
    
public:
    // constructors
    Owner():Person()
    {

    }
    Owner(string name, string cnic, int age, string fatherName, string country, string city)
     :Person(name,cnic,age,fatherName,country,city)
    {
    }
    void print()override
    {
        base::print();
        
        
    }

};

#endif // Owner_H