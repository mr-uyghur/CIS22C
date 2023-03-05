#ifndef KRONE_H
#define KRONE_H



#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <cstdint>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    double info;
    struct node *left;
    struct node *right;
} *root;


#endif