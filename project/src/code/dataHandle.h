#define _HAS_STD_BYTE 0
#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <iostream>
#include <string>
using namespace std;
class DataHandle
{
private:
    DataHandle()
    {
    }
    DataHandle(const DataHandle &) = delete;
    DataHandle &operator=(const DataHandle &) = delete;

public:
    static DataHandle &GetInstance()
    {
        static DataHandle instance;
        return instance;
    }
    bool valiDateAge(int age)
    {
        return (age>18&&age<=130);
    }
    bool checkEnterBalnce(double balance)
    {
        return balance >= 0;
    }
    string lowerCase(string str)
    {
        string ans = "";
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] > 'A' && str[i] < 'Z')
            {
                char ch = str[i] - 'A' + 'A';
                ans += ch;
            }
            else
            {
                ans += str[i];
            }
        }
        return ans;
    }
    void throughError()
    {
        cout<<"Error! \n";
    }
};

#endif
