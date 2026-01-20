#ifndef Employee_H
#define Employee_H

#include <string>
#include <iostream>
#include "person.h"
using namespace std;

class Employee : public Person
{
private:
    double employeeSalary;
    double monthlyBonus;
    double yearlyBonus;
    double yearlyIncreament;

protected:
    // member variables
public:
    // constructors
    Employee() : Person()
    {
    }
    Employee(string name, string cnic, int age, string fatherName, string country, string provisince = "", string city, int streetNo, int postCode, double salay, double bonus, double yearInc, double yearBonus) : Person(name, cnic, age, fatherName, country, provisince, city,postCode,streetNo)
    {
        this->employeeSalary = salay;
        this->monthlyBonus = bonus;
        this->yearlyIncreament = yearInc;
        this->yearlyBonus = yearBonus;
    }
    void setMonthBonus(double bonus)
    {
        this->monthlyBonus = bonus;
    }
    void setYearBonus(double yearBonus)
    {
        this->yearlyBonus = yearBonus;
    }
    void setSalary(double sal)
    {
        this->employeeSalary = sal;
    }
    void setYearIncrement(double yearInc)
    {
        this->yearlyIncreament = yearInc;
    }
    double getSalary() const
    {
        return employeeSalary;
    }
    double getMonthlyBonue() const
    {
        return this->monthlyBonus;
    }
    double getYearlyIncreament() const
    {
        return this->yearlyIncreament;
    }
    double getYearlyBonus() const
    {
        return this->yearlyBonus;
    }
};

#endif // Admin_H