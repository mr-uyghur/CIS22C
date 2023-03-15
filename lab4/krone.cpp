// Lab 04
// Bryan Chan and Ali Halmamat  
// The purpose of this assignment is to implement a binary tree ADT which will take in Krone objects.

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