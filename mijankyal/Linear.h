#pragma once
#include "Function.h"

class Linear : public Func {
private:
    double a;
    double b;

public:
    Linear(const double newA = 0, const double newB = 0) {
        this->setA(newA);
        this->setB(newB);
    }

    Linear(const Linear & source) {
        this->a = source.a;
        this->b = source.b;
    }

    void setA(const double value) {
        this->a = value;
    }

    double getA() const {
        return this->a;
    }

    void setB(const double value) {
        this->b = value;
    }

    double getB() const {
        return this->b;
    }

    double def() override {
        return this->a;
    }

    double op(const double x) override {
        return this->a * x + this->b;
    }

    friend ostream& operator <<(ostream &os, const Linear &source) {
        os << static_cast<const Func&>(source);
        os << source.a << "x ";
        char symbol = '+';
        if (source.b < 0) {
            symbol = '-';
        }
        os << symbol;
        os << " ";
        os << abs(source.b);
        os << endl;

        return os;
    }

    Linear* operator +(const Linear& source) {
        double newA = this->a + source.a;
        double newB = this->b + source.b;
        return new Linear(newA, newB);
    }

    Linear* operator -(const Linear& source) {
        double newA = this->a - source.a;
        double newB = this->b - source.b;
        return new Linear(newA, newB);
    }
};
