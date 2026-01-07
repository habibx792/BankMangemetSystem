#define _HAS_STD_BYTE 0
#ifndef customre_H
#define customre_H
#include <iostream>
#include <string>
#include "dataHandle.h"
using namespace std;
class Customer
{
private:
    string customerName;
    string customerFatherName;
    string accountNo;
    int customerAge;
    double customerBalance;
    DataHandle &d = DataHandle::GetInstance();

public:
    Customer()
    {
        customerName = "";
        customerFatherName = "";
        customerAge = 0;
        customerBalance = 0;
    }
    Customer(string name, string fatherName, int age, double balance)
    {
        this->customerFatherName = d.lowerCase(fatherName);
        this->customerName = d.lowerCase(name);
        this->customerAge = d.valiDateAge(age);
        if (d.checkEnterBalnce(balance))
        {
            this->customerBalance = balance;
            cout << "You Accout is Created \n";
        }
        else
        {
            cout << "Your Account Is Temperary Created Please Enter Correct  Balance \n";
        }
    }
    // === Data Correction Method \n;
    void setCorrecBalance()
    {
        double balance = 0;
        cout << "Enter Your Correct Balance \n";
        cin >> balance;
        while (!d.checkEnterBalnce(balance))
        {
            cout << "Enter Your correct Balance \n";
            cin >> balance;
        }
        this->customerBalance = balance;
    }
    void setCustomerName(string name)
    {
        this->customerName = d.lowerCase(name);
    }
    string &getCustomerName()
    {
        return customerName;
    }
    void setCustomerFatherName(string fatherName)
    {
        this->customerFatherName = fatherName;
    }
    string &getCustomerFatherName()
    {
        return customerFatherName;
    }
    void setCustomerAge(int age)
    {
        if (d.valiDateAge(age))
            this->customerAge = age;
        else
        {
            cout << "Please Enter Correct Age \n";
        }
    }
};

#endif