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

    // setters
    void setmemberName(const string& value);
};

#endif // Bank_H