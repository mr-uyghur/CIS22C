#ifndef KRONE_H
#define KRONE_H

#include <iostream>
#include "Currency.cpp"

using namespace std;

// Class Krone .
class Krone : public Currency
{
    // Access specifier:
private:
    // Members:
    string nameOfCurrency;

public:
    // constructor
    Krone()
    {
        nameOfCurrency = "Krone";
    }
    // constructor
    Krone(double value) : Currency(value)
    {
        nameOfCurrency = "Krone";
    }
    // Print function.
    void print()
    {
        cout << get_whole() << '.' << get_fraction() << " Krones" << endl;
    }

   
};
#endif