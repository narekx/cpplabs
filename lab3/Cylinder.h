#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265359

class Cylinder {
public:
    static int objectCount;

    static int getObjectCount() {
        return Cylinder::objectCount;
    }

    Cylinder(double r1 = 1, double h1 = 1) {
        objectCount++;
        r = r1;
        h = h1;
    }

    Cylinder(const Cylinder& obj)
    {
        r = obj.r;
        h = obj.h;
    }

    Cylinder(Cylinder&& source)
            : r{ source.r }, h{ source.h }
    {
//        cout << "Move Constructor for " << endl;
    }

    ~Cylinder() {
        objectCount--;
    }

    double getR() const {
        return r;
    }

    double getH() const {
        return h;
    }

    void setProps(double r1 = 1, double h1 = 1) {
        r = r1;
        h = h1;
    }

    friend ostream& operator<<(ostream& os, const Cylinder& obj) {
        os << "(" << obj.r << ", " << obj.h << ") ";
        return os;
    }

    friend istream& operator>>(istream& input, Cylinder& obj) {
        input >> obj.r >> obj.h;
        return input;
    }

    void operator=(const Cylinder& obj) {
        if (*this != obj) {
            r = obj.r;
            h = obj.h;
        }
    }

    bool operator==(const Cylinder& obj) const {
        return r == obj.r && h == obj.h;
    }

    bool operator!=(const Cylinder& obj) const {
        return !(*this == obj);
    }

    bool operator>(const Cylinder& obj) const {
        return this->volume() > obj.volume();
    }

    bool operator<(const Cylinder& obj) const {
        return this->volume() < obj.volume();
    }

    double volume() const {
        return PI * r * r * h;
    }

    double baseArea() const {
        return PI * r * r;
    }

    double lateralArea() const {
        return 2 * PI * r * h;
    }

    double surfaceArea() const {
        return 2 * baseArea() + lateralArea();
    }

    double arancqayinArea() const {
        return 2 * r * h;
    }

    double multiVolume(double k) const {
        return k * volume();
    }
private:
    double r;
    double h;
};