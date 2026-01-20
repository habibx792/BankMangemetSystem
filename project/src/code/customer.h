#define _HAS_STD_BYTE 0
#ifndef customre_H
#define customre_H
#include <iostream>
#include <string>
#include "dataHandle.h"
#include "person.h"
using namespace std;
DataHandle &d = DataHandle::GetInstance();
class Customer : public Person
{
private:
protected:
    string customerAccountNo;
    string customerAccountType;

public:
    Customer() : Person()
    {
    }
    Customer(string name, string cnic, int age, string fatherName, string country, string provisince , string city, int streetNo, int postCode) : Person(name, cnic, age, fatherName, country, provisince, city, postCode, streetNo)
    {
        this->customerAccountNo = "";
        this->customerAccountType = "basic";
    }
    void setCustomerAccountNo(string accountNo)
    {
        this->customerAccountNo = accountNo;
    }
    void setAccountType(string accountType)
    {
        this->customerAccountType = accountType;
    }
    string getAccountType() const
    {
        return this->customerAccountType;
    }
    string getCustomerAccountNo() const
    {
        return this->customerAccountNo;
    }
    void print()
    {
        Person::print();
        cout << "Account No :->" << customerAccountNo << endl;
        cout << "AccountType :-> " << customerAccountType << endl;
    }
};

#endif