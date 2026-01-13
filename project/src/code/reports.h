#ifndef Report_H
#define Report_H

#include <string>
#include <iostream>
using namespace std;

class Report
{
private:
    // member variables
protected:
    string reportType;

public:
    // constructors
    Report()
    {
        this->reportType = "NULL";
    }
    Report(string type)
    {
        this->reportType = type;
    }
    void setReportType(string type)
    {
        this->reportType = type;
    }
};
class customerReort
{
};
class atmReport
{
};
class emplyeeRepory
{
};
#endif // Report_H