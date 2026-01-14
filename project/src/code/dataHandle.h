#define _HAS_STD_BYTE 0
#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <iostream>
#include <string>
#include <vector>
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
        return (age > 18 && age <= 130);
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
    vector<int> calculateDays(int sYear, int sMonth, int sDay)
    {
        vector<int>ans;
        return ans;
    }
    bool isLeap(int year)
    {
        if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
        {
            return true;
        }
        return false;
    }
    string captilize(string str)
    {
        string ans = "";
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                char ch = 'A' + str[i] - 'a';
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
        cout << "Error! \n";
    }
    int getInput(int min,int max)
    {
        int choice;
        while(true)
        {
            cout<<"Enter a Choice  ( "<<min<<" between "<<max<<" ) "<<endl;
            cin>>choice;
            if(cin.fail()||choice<min||choice>max)
            {
                cin.clear();
                cin.ignore();
                cout<<"lease Enter A valid Information \n";
            }
            else 
            {
                cin.ignore();
                return choice;
                /* code */
            }
            
        }
    }
    void wordCaptilize(string word)
    {
        vector<string>ans;
        int n=word.length();
        string word="";
        bool found=false;
        for(int i=0;i<n;i++)
        {
            
            if(word[i]!=' ')
            {
                char ch=word[i];
                if(ch>='a'&&ch<='z'&&!found)
                {
                    ch='A'+ch-'a';
                    found=true;
                }
                else{
                    ch='a'+ch-'A';
                    word+=ch;
                }
                continue;
            }

        }
    }
};

#endif
