#ifndef Adress_H
#define Adress_H

#include <string>
#include <iostream>
using namespace std;

class Address
{
private:
    string countryName;
    string provisinceName;
    string cityName;
    int streetNo;
    int postalCode;
protected:
    // member variables
public:
    // constructors
    Address()
    {
        this->countryName = "";
        this->provisinceName = "";
        this->cityName = "";
        this->streetNo = 0;
        this->postalCode = 0;
    }
    Address(string countryName, string provisinName, string city, int streetNo, int postAdress)
    {
        this->countryName = countryName;
        this->provisinceName = provisinName;
        this->cityName = city;
        this->postalCode = postAdress;
        this->streetNo = streetNo;
    }
    void setCountry(string country)
    {
        this->countryName = country;
    }
    void setProvisince(string provisince)
    {
        this->provisinceName = provisince;
    }
    void setCity(string city)
    {
        this->cityName = cityName;
    }
    void setStreetNo(int streetNo)
    {
        if (streetNo == 0)
        {
        }
        else
        {
            this->streetNo = streetNo;
        }
    }
    void setPostalCode(int postalCode)
    {
        if (postalCode == 0 || postalCode < 0)
        {
        }
        else
        {
            this->postalCode = postalCode;
        }
    }
    string getCountryName()
    {
        return this->countryName;
    }
    string getProvisinName()
    {
        return this->provisinceName;
    }
    string getCityName()
    {
        return this->cityName;
    }
    double getStreeNo()
    {
        return this->streetNo;
    }
    double getPostaCode()
    {
        return this->postalCode;
    }
    void print()
    {
        cout<<"Country : "<<this->countryName;
        cout<<"Provisince : "<<this->provisinceName;
        cout<<"City : "<<this->cityName;
        cout<<"StreeNo : "<<this->streetNo;
        cout<<"PostalCode  : "<<this->postalCode;
    }
};

#endif // Adress_H