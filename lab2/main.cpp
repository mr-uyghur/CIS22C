

#include <iostream>
#include "currency.cpp"
#include "krone.cpp"
#include "soum.cpp"


using namespace std;


int Main()
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