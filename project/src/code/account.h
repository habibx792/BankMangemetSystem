#ifndef Account_H
#define Account_H
#include <string>
#include <iostream>

#include <ctime>
using namespace std;
class Account
{
private:
protected:
    string accountNo;
    string accountType;
    string accountStatus;
    double currentAccountBalance;
    string customerId;

public:
    Account()
    {
        this->accountNo = "";
        this->accountStatus = "block";
        this->currentAccountBalance = 0;
        this->customerId = "";
        this->accountType = "current";
    }
    string createAccount(int branchCode, string cnicMiddle_5, int age)
    {
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);
        int year = 1900 + localTime->tm_year;
        int month = localTime->tm_mon;
        string strAge = to_string(age);
        string strYear = to_string(year);
        string strMonth = to_string(month);
        string brCode = to_string(branchCode);
        accountNo = brCode + cnicMiddle_5 + strAge + strYear + strMonth;
        return accountNo;
    }
    void setBalance(double balance)
    {
        this->currentAccountBalance = balance;
    }
    double getCurrentBalance()
    {
        return this->currentAccountBalance;
    }
    void changeAccountType(string type)
    {
        this->accountType = type;
    }
    string getAccountType() const
    {
        return this->accountType;
    }
    void diplayCurrentAccount() const
    {
        cout << accountNo << endl;
    }
};
class SavingAccount : public Account
{
private:
    static double interestRate;

public:
    SavingAccount() : Account()
    {
        this->accountType = "saving";
    }
    static void setRate(double rate)
    {
        interestRate = rate;
    }
    

    static double
    getRate()
    {
        return interestRate;
    }
};
#endif // Account_H