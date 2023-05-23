#pragma once
#include <iostream>
#include <string>
using namespace std;

class Func {
public:
    virtual double def() = 0;
    virtual double op(const double x) = 0;

    friend ostream& operator <<(ostream &os, const Func &source) {
        return os;
    }
};
