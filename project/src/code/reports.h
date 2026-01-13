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
class customerReort : public Report
{
};
class atmReport : public Report
{
};
class emplyeeRepory : public Report
{
};
#endif // Report_H