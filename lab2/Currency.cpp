#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// class Currency
class Currency
{
    // Access specifier:
private:
    // Members:
    // Whole part of the Currency
    int whole;
    // fractional part of the Currency.
    int fraction;
public:
    // Accessor for whole Currency.
    int get_whole()
    {
        return whole;
    }

    // Accessor for fractional currency.
    int get_fraction()
    {
        return fraction;
    }
    // Mutator/Setter for whole part.
    void set_whole(int input_whole)
    {
        whole = input_whole;
    }
    // Mutator/Setter for fractional Currency.
    void set_fraction(int input_fractional)
    {
        fraction = input_fractional;
    }
    // Default constructor for setting whole and fractional part to zero:
    Currency()
    {
        whole = 0;
        fraction = 0;
    }
    // Parameterized constructor for setting whole and fractional part.
    Currency(double input)
    {
        whole = int(input);
        fraction = (int)round(fabs(input - trunc(input)) * 1e2);
    }
    // Copy constructor
    Currency(const Currency &p1)
    {
        whole = p1.whole;
        fraction = p1.fraction;
    }
    // Destructor.
    ~Currency()
    {
    }
    // Add method.
    void add(double input)
    {
        whole = whole + int(input);
        fraction = fraction + (int)round(fabs(input - trunc(input)) * 1e2);
        ;
    }
    // Subtract method.
    void subtract(double input)
    {
        int inputwhole = int(input);
        int inputfraction = (int)round(fabs(input - trunc(input)) * 1e2);
        if (whole - inputwhole < 0 || fraction - inputfraction < 0)
        {
            cout << "Invalid subtraction." << endl;
        }
        else
        {
            whole = whole - inputwhole;
            fraction = fraction - inputfraction;
        }
    }
    // Check equality of currencies.
    bool isEqual(Currency c1, Currency c2)
    {
        if (c1.whole == c2.whole)
        {
            if (c1.fraction == c2.fraction)
                return true;
        }
        return false;
    }
    // Check greater of currencies.
    bool isGreater(Currency c1, Currency c2)
    {
        if (c1.whole > c2.whole)
            return true;
        if (c1.fraction == c2.fraction)
        {
            if (c1.fraction > c2.fraction)
                return true;
            else
                return false;
        }
        return false;
    }

    void print()
    {
        cout << get_whole() << '.' << get_fraction() << endl;
    }
   
};
#endif