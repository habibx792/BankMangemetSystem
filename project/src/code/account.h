#ifndef Account_H
#define Account_H
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Account
{
private:
    string account;
    Account()
    {
        account = "";
    }
    Account(const Account &) = delete;
    Account operator&=(const Account &) = delete;

protected:
    // member variables
public:
    static Account &
    getInstance()
    {
        static Account at;
        return at;
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
         account = brCode + cnicMiddle_5 + strAge + strYear + strMonth;
        return account;
    }
    void diplayCurrentAccount()const
    {
        cout<<account<<endl;
    }
    
};

#endif // Account_H