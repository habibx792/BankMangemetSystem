#ifndef Bank_H
#define Bank_H

#include <string>
using namespace std;

class Bank {
private:
    // member variables
    string memberName;

public:
    // constructors
    Bank
();
    

    // getters
    string getmemberName() const;
    virtual void withDraw(int amount, string accountNo)
    {
    }
    int getBalance()
    {

    }
    virtual void deposite(int amount, string accountNo)
    {
    }
    // setters
    void setmemberName(const string& value);
};

#endif // Bank_H