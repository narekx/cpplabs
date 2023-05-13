#pragma once
#include <iostream>
using namespace std;
#define PI 3.141592

class Shape3D {
public:
    Shape3D() {
    }

    Shape3D(const Shape3D &source) {
    }

    virtual Shape3D& operator =(const Shape3D &source) {
        return *this;
    }

    virtual double surfaceArea() const {
        return 0;
    }

    virtual double volume() const {
        return 0;
    }

    virtual void print() {
        cout << "Shape 3D" << endl;
    }
};