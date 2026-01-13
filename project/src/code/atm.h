#ifndef ATM_H
#define ATM_H
#include "bank.h"
#include <string>
using namespace std;
class ATM : protected Bank
{
private:
   
    string memberName;

public:
    ATM()
    {

    }
    void withDraw(int amount,string accountNo)
    {

    }
    string  checkBalance(string AccountNo)
    {
        string ans="";


        return ans;


    }
    void deposite(int amount,string accountNo)
    {
        
    }
    void sendMoney()
    {
        
    }
};

#endif // ATM_H