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
    double customerAccountBalance;

public:
    Customer() : Person()
    {
    }
    Customer(string name, string cnic, int age, string fatherName, string country, string city) : Person(name, cnic, age, fatherName, country, city)
    {
        this->customerAccountNo = "";
        this->customerAccountType="basic";
        this->customerAccountBalance = 0;
    }
    void setCustomerAccountNo(string accountNo)
    {
        this->customerAccountNo = accountNo;
    }
    void setAccountType(string accountType)
    {
        this->customerAccountType=accountType
    }
    string getAccountType()const
    {
        return this->customerAccountType;
    }
    void setBalance(double accountBalance)
    {
        this->customerAccountBalance = accountBalance;
    }
    string getCustomerAccountNo() const
    {
        return this->customerAccountNo;
    }
    double getCurrentBalance() const

    {
        return this->customerAccountBalance;
    }
    void print()
    {
        Person::print();
        cout << "Account No :->" << customerAccountNo << endl;
        cout<<"AccountType :-> "<<customerAccountType<<endl;
        cout << "Current Balance :->  " << customerAccountBalance << endl;
    }
};

#endif