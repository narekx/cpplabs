#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265359

struct Point {
    double x;
    double y;
};

class Circle {
private:
    double r;
    Point coords;

public:
    Circle() {
        coords = {0, 0};
        r = 1;
    }

    Circle(Point& p, double r1 = 1) {
        coords = p;
        r = r1;
    }

    Circle(const Circle& obj)
    {
        r = obj.r;
        coords = obj.coords;
    }

    ~Circle() {
        //cout << "Destructor" << endl;
    }

    double getR() const {
        return r;
    }

    Point getCoords() const {
        return coords;
    }

    void setProps(Point& p, double r1 = 1) {
        r = r1;
        coords = p;
    }

    friend ostream& operator<<(ostream& os, const Circle& obj) {
        os << "[" << obj.r << "]" << "(" << obj.coords.x << ", " << obj.coords.y << ") ";
        return os;
    }

    friend istream& operator>>(istream& input, Circle& obj) {
        input >> obj.r >> obj.coords.x >> obj.coords.y;
        return input;
    }

    bool operator==(const Circle& obj) const {
        return r == obj.r && coords.x == obj.coords.x && coords.y == obj.coords.y;
    }

    bool operator!=(const Circle& obj) const {
        return !(*this == obj);
    }

    bool operator>(const Circle& obj) const {
        return this->r > obj.r;
    }

    bool operator<(const Circle& obj) const {
        return this->r < obj.r;
    }

    double length() const {
        return 2 * PI * r;
    }

    double area() const {
        return PI * r * r;
    }

    double distance(const Point& p) const {
        return sqrt(pow((coords.x - p.x), 2) + pow(coords.y - p.y, 2));
    }

    bool inCircle(const Point& p) const {
        return distance(p) <= r;
    }

    void moveX(double value) {
        coords.y += value;
    }

    void moveY(double value) {
        coords.x += value;
    }

    int getCrossCount(const Circle& obj) const {
        double d = distance(obj.coords);
        if (d == obj.r + r || d == abs(obj.r - r)) {
            return 1;
        }

        if (abs(r - obj.r) < d && d < obj.r + r) {
            return 2;
        }

        return 0;
    }

    double multiArea(int k) const {
        return k * area();
    }

    void printTangent(Point& p) {
        double m = (-1) * (p.x - coords.x) / (p.y - coords.y);
        double c = (-1) * m * p.x + p.y;
        cout << "y=" << m << "x+" << c;
    }
};