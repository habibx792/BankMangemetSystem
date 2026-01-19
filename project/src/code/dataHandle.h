#define _HAS_STD_BYTE 0
#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
class DataHandle
{
private:
    DataHandle()
    {
    }
    DataHandle(const DataHandle &) = delete;
    DataHandle &operator=(const DataHandle &) = delete;
    vector<int> getRAMInfo()
    {
        MEMORYSTATUSEX mem;
        mem.dwLength = sizeof(mem);

        GlobalMemoryStatusEx(&mem);
        vector<int> ramDetails;

        std::cout << "RAM Used (%): " << mem.dwMemoryLoad << std::endl;
        std::cout << "Total RAM (MB): "
                  << mem.ullTotalPhys / (1024 * 1024) << std::endl;
        std::cout << "Available RAM (MB): "
                  << mem.ullAvailPhys / (1024 * 1024) << std::endl;
        ramDetails.push_back(mem.ullAvailPhys / (1024 * 1024));
        ramDetails.push_back(mem.ullTotalPhys / (1024 * 1024));
        ramDetails.push_back(mem.dwMemoryLoad);
        return ramDetails;
    }
    unsigned long long addressEntropy()
    {
        int x;
        int *p = new int;
        unsigned long long e = (unsigned long long)&x ^ (unsigned long long)p;
        delete p;
        return e;
    }
    double getCPUUsage()
    {
        static FILETIME prevIdle, prevKernel, prevUser;
        FILETIME idle, kernel, user;

        GetSystemTimes(&idle, &kernel, &user);

        auto diff = [](FILETIME a, FILETIME b)
        {
            return ((unsigned long long)b.dwLowDateTime |
                    ((unsigned long long)b.dwHighDateTime << 32)) -
                   ((unsigned long long)a.dwLowDateTime |
                    ((unsigned long long)a.dwHighDateTime << 32));
        };

        auto idleDiff = diff(prevIdle, idle);
        auto kernelDiff = diff(prevKernel, kernel);
        auto userDiff = diff(prevUser, user);

        prevIdle = idle;
        prevKernel = kernel;
        prevUser = user;

        auto total = kernelDiff + userDiff;
        return total ? (1.0 - (double)idleDiff / total) * 100.0 : 0.0;
    }
    POINT getMousePosition()
    {
        POINT p;
        GetCursorPos(&p);
        return p;
    }
    void getRandomData( vector<int>&randomData)
    {
       
        POINT p=getMousePosition();
        int x=p.x;
        int y=p.y;
        double cpuUse=getCPUUsage();
        randomData = getRAMInfo();
        long long entropy = addressEntropy();
        randomData.push_back(x);
        randomData.push_back(y);
        randomData.push_back(cpuUse);
        randomData.push_back(entropy);
    }
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
        vector<int> ans;
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
    int getInput(int min, int max)
    {
        int choice;
        while (true)
        {
            cout << "Enter a Choice  ( " << min << " between " << max << " ) " << endl;
            cin >> choice;
            if (cin.fail() || choice < min || choice > max)
            {
                cin.clear();
                cin.ignore();
                cout << "lease Enter A valid Information \n";
            }
            else
            {
                cin.ignore();
                return choice;
                /* code */
            }
        }
    }
    char makeBig(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'A' + ch - 'a';
        }
        return ch;
    }
    char makeSmall(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = 'a' + ch - 'A';
        }
        return ch;
    }
    void wordCaptilize(string str)
    {
        vector<string> ans;
        int n = str.length();
        string word = "";
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            char ch = str[i];
            if (ch != ' ')
            {
                if (!found)
                {
                    ch = makeBig(ch);
                    word += ch;
                    found = true;
                }
                else
                {
                    ch = makeSmall(ch);
                    word += ch;
                }
            }
            else
            {
                found = false;
                if (word != "")
                {
                    ans.push_back(word);
                    word = "";
                }
            }
        }
    }
    std::string getCurrentDateTime()
    {
        // Get current time from system clock
        auto now = std::chrono::system_clock::now();

        // Convert to time_t (seconds since epoch)
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        std::tm *local_time = std::localtime(&now_time);

        // Format: YYYY-MM-DD HH:MM:SS
        char buffer[20];
        std::strftime(buffer, sizeof(buffer),
                      "%Y-%m-%d %H:%M:%S", local_time);

        return std::string(buffer);
    }
    bool validateCnic(string &cnic) const
    {
        return cnic.length() < 0 && cnic.length() > 13;
    }
    string getMiddleFive(string cnic)
    {
        int index = 5;
        string middleNo = "";
        if (validateCnic(cnic))
        {
            throughError();
            return "NULL";
        }
        for (index; index <= 10; index++)
        {
            middleNo += cnic[index];
        }
        cout << "Dt->Middled :" << middleNo << endl;
        return middleNo;
    }
    string convertStandardFormat(string cnic)
    {
        string ans = "";
        int n = cnic.length();
        for (int i = 0; i < n; i++)
        {
            if (i == 4)
            {
                ans += cnic[i];
                ans += '-';
            }
            else if (i == 11)
            {
                ans += cnic[i];
                ans += '-';
            }
            else
            {
                ans += cnic[i];
            }
        }
        cout << "Dt->format :" << ans << endl;
        // ans+=cnic[i];
        return ans;
    }
    // create a method that give me a random Number type

    string getRandomNoStr()
    {
        return "hel";
    }
    long long getRandomNumber()
    {
        return 0;
    }






    //testing method()
    void printSystemInfo()
    {
        vector<int>info;
        getRandomData(info);
        int n=info.size();
        for(int i=0;i<n;i++)
        {
            cout<<info[i]<<" : ";
        }
        cout<<endl;
    }
};
#endif
