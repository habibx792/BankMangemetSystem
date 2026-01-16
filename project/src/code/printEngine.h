#ifndef PrintEngine_H
#define PrintEngine_H

#include <string>
#include <iostream>
using namespace std;

class PrintEngine {
private:

    // member variables
public:
    // constructors
    PrintEngine();
    void WelcomeNote()
    {
        cout<<"============================Welcome Habib Bank Limited=====================\n";
    }
    void printMainMenu()
    {
        cout<<"1 for Owner \n";
        cout<<"2 for Admin \n";
    }
    
    

};

#endif // PrintEngine_H