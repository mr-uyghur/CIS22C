#include <iostream>
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





// Class Soum .
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





int main()
{
    Currency ptr[2];
    ptr[0] = Soum(0.0);
    ptr[1] = Krone(0.0);
    char op1, op2;
    string nameOfCurrency;
    double value;
    while (true)
    {
        cin >> op1 >> op2 >> value >> nameOfCurrency;
        if (op1 == 'a')
        {
            if (op2 == 'k' && nameOfCurrency == "Krone")
                ptr[0].add(value);
            else if (op2 == 's' && nameOfCurrency == "Soum")
                ptr[1].add(value);
            else
                cout << "Invalid addition" << endl;
            ptr[0].print();
            ptr[1].print();
        }
        else if (op1 == 's')
        {
            if (op2 == 'k' && nameOfCurrency == "Krone")
                ptr[0].subtract(value);
            else if (op2 == 's' && nameOfCurrency == "Soum")
                ptr[1].subtract(value);
            else
                cout << "Invalid Subtraction." << endl;
            ptr[0].print();
            ptr[1].print();
        }
        else
            break;
    }
    return 0;
}