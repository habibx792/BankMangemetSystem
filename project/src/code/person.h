#ifndef Person_H
#define Person_H
#include <string>
#include <iostream>
#include "dataHandle.h"
using namespace std;
DataHandle &dt = DataHandle::GetInstance();
class Person
{
private:
protected:
    string personName;
    string personFatherName;
    int personAge;
    string personCnic;
    string personCountry;
    string personCity;

public:
    // constructors
    Person()
    {
        this->personAge = 0;
        this->personName = "";
        this->personCnic = "";
        this->personFatherName = "";
        this->personCountry = "";
        this->personCity = "";
    }
    Person(string name, string cnic, int age, string fatherName, string country, string city)
    {
        this->personName = name;
        this->personCnic = cnic;
        if (dt.valiDateAge(age))
        {
            this->personAge = age;
        }
        else
        {
            dt.throughError();
            cout << "Please Enter Correct Age \n";
            personAge = 0;
        }
        this->personAge = age;
        this->personFatherName = fatherName;
        this->personCountry = country;
        this->personCity = city;
    }
    void setPesonName(string name)
    {
        this->personName = name;
    }
    void setPersonCnic(string cnic)
    {
        this->personCnic = cnic;
    }
    void setPersonAge(int age)
    {
        if (dt.valiDateAge(age))
        {
            this->personAge = age;
        }
        else
        {
            dt.throughError();
            cout << "Please Enter correct Age \n";
        }
    }
    void setPersonFatherName(string fatherName)
    {
        this->personFatherName = fatherName;
    }
    void setPersonCountry(string country)
    {
        this->personCountry = country;
    }
    void setPersonCity(string city)
    {
        this->personCity = city;
    }
    string getPersonName()const
    {
        return this->personName;

    }
    string getPersonCnic()const
    {
        return this->personCnic;

    }
    int getPersonAge()const
    {
        return this->personAge;
    }
    string getPersonFatherName()const
    {
        return this->personFatherName;
    }
    string getPersonCountry()const
    {
        return this->personCountry;
    }
    string getPersonCity()const
    {
        return this->personCity;
    }
    

};

#endif // Person_H