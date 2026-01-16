#define _HAS_STD_BYTE 0
#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <iostream>
#include <string>
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
    void wordCaptilize(string word)
    {
        vector<string> ans;
        int n = word.length();
        string word = "";
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
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
};

#endif
