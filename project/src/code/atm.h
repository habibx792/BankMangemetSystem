#ifndef ATM_H
#define ATM_H
#include "bank.h"
#include <string>
using namespace std;
class ATM : protected Bank
{
private:
    // member variables
    string memberName;

public:
    ATM();
    string getmemberName() const;
    void setmemberName(const string& value);
};

#endif // ATM_H