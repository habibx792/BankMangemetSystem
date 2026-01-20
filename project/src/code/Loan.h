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
    double loanAmount;
    double rate;
    string loanIssueDate;
    string loanReturnDate;
    double totalMarkup;

public:
    // constructors
    Loan();
    void setLoanAmount(double amount)
    {
        this->loanAmount;
    }
     double getLoanAmount()
    {
        return loanAmount;
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