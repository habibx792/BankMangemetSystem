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
    int durationYear;
    double loanAmount;
    static double markUpRate;
    string loanIssueDate;
    string loanReturnDate;
    double totalMarkup;
    string customerAccountNo;
public:
    // constructors
    Loan()
    {
        this->type = "general";
        this->loanAmount = 0;
        this->durationYear = 0;
        this->loanIssueDate = "";
        this->loanReturnDate = "";
        this->customerAccountNo= "";
    }
    static void setMarkUpRate(double rate)
    {
        markUpRate = rate;
    }
    Loan(string type, string customerAccountNo, double amount, int duration, string issueDate, string returnDate)
    {
        this->type = type;
        this->customerAccountNo = customerAccountNo;
        this->loanAmount = amount;
        this->durationYear = duration;
    }
    void virtual setLoanType()
    {
        this->type = "general";
    }
    string getLoanType()
    {
        return type;
    }
    void calcuLateMarkup()
    {
    }
    double getTotalMarkup()
    {
        return totalMarkup;
    }
    void setLoanReturnDate(string date)
    {
        this->loanReturnDate = date;
    }
    void setLoanIssueDate(string date)
    {
        this->loanIssueDate = date;
    }
    void setLoanAmount(double amount)
    {
        this->loanAmount;
    }
    double getLoanAmount()
    {
        return loanAmount;
    }
    void virtual setMarkUp(double rate)
    {
        this->markUpRate = rate;
    }
    double getMarkUpRate()
    {
        return markUpRate;
    }
};
#endif