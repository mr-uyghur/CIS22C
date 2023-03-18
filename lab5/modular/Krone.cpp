#ifndef KRONE_H
#define KRONE_H

#include <iostream>
using namespace std;

class Krone{
    public:
    float* hash;
    int i;
    int size,m,n;
    Krone(int n){
        hash=new float[n];
        i=0;
        size=n;
        m=2;
        this->n=3;
    }
     void insert(float amount) {
         int w=(int)amount;
         float f=amount-w;
         hash[(int)((m*w)+(n*f))%size]=amount;         
    }
     int find(float amount) {
        int w=(int)amount;
         float f=amount-w;
        if(hash[(int) ((m*w)+(n*f))%size]==amount) {
            return (int) ((m*w)+(n*f))%size;
        }
        return -1;
    }
};

#endif