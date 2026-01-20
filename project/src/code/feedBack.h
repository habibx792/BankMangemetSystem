#ifndef FeedBack_H
#define FeedBack_H

#include <string>
#include <iostream>
using namespace std;

class FeedBack
{
private:
    string customerName;
protected:
    string problemStatement;
    // member variables
public:
    // constructors
    FeedBack()
    {
        this->customerName = "";
        this->problemStatement = "";
    }
    FeedBack(string name,string problemSt)
    {
        this->customerName=name;
        this->problemStatement=problemSt;
    }
    void setCustomerName(string name)
    {
        this->customerName=name;
    }
    void setProblemStatement(string problemSt)
    {
        this->problemStatement=problemSt;
    }
    string getPromlemStatem()
    {
        return this->problemStatement;
    }
    string customerName()
    {
        return this->customerName;
    }
};

#endif // FeedBack_H