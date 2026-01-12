#ifndef Loan_H
#define Loan_H

#include <string>
#include <iostream>
using namespace std;

class Loan
{
private:
    // member variabl
protected:
    string type;
    double amount;

public:
    // constructors
    Loan();
    virtual void setLoanAmount(double amount)
    {
    }
    virtual double getLoanAmount()
    {
        return amount;
    }
};
class HomeLoan : public Loan
{
};
class CarLoan : public Loan
{
};
class BusinessLoan : public Loan
{
};

#endif 