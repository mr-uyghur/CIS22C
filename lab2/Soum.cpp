#ifndef SOUM_H
#define SOUM_H

#include <iostream>
#include "Currency.cpp"
using namespace std;

class Soum : public Currency
{
    // Access specifier:
private:
    // Members:
    string nameOfCurrency;

public:
    // constructor
    Soum(double value) : Currency(value)
    {
        nameOfCurrency = "Krone";
    }
    // Print function.
    void print()
    {
        cout << get_whole() << '.' << get_fraction() << " Soums" << endl;
    }

    
};
#endif