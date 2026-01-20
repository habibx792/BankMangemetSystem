#ifndef Person_H
#define Person_H
#include <string>
#include <iostream>
#include "dataHandle.h"
#include "adress.h"
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
    Address ad;

public:
    // constructors
    Person()
    {

        this->personAge = 0;
        this->personName = "";
        this->personCnic = "";
        this->personFatherName = "";
    }
    Person(string name, string cnic, int age, string fatherName, string country, string provisince = "", string city, int streetNo, int postCode)
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
        this->ad.setCountry(country);
        this->ad.setProvisince(provisince);
        this->ad.setCity(city);
        this->ad.setStreetNo(streetNo);
        this->ad.setPostalCode(postCode);
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
        this->ad.setCountry(country);
    }
    void setPersonCity(string city)
    {
        this->ad.setCity(city);
    }
    void setProvisince(string provisince)
    {
        this->ad.setProvisince(provisince);
    }
    void setStreetNo(int streetNo)
    {
        this->ad.setStreetNo(streetNo);
    }
    void setPostalCode(int postalCode)
    {
        this->ad.setPostalCode(postalCode);
    }
    Address &getAdress()
    {
        return ad;
    }
    string getPersonName() const
    {
        return this->personName;
    }
    string getPersonCnic() const
    {
        return this->personCnic;
    }
    int getPersonAge() const
    {
        return this->personAge;
    }
    string getPersonFatherName() const
    {
        return this->personFatherName;
    }
    virtual void print()
    {
        cout << "============Personal Detail=========== \n";
        cout << "Name :-> " << this->personName << endl;
        cout << "Cnic :->" << this->personCnic << endl;
        cout << "Age  :->" << this->personAge << endl;
        cout << "FatherName : ->" << this->personFatherName << endl;
        ad.print();
    }
};
#endif // Person_H