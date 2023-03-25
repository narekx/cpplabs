#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    Point(double x1 = 0, double y1 = 0) {
        x = x1;
        y = y1;
    }

    Point(const Point& obj)
    {
        x = obj.x;
        y = obj.y;
    }

    ~Point() {}

    double getX() const {
        return this->x;
    }

    double getY() const {
        return this->y;
    }

    void setX(double value) {
        this->x = value;
    }

    void setY(double value) {
        this->y = value;
    }

    void setCoords(double x1, double y1) {
        this->setX(x1);
        this->setY(y1);
    }

    int getQuarter() const {
        if (x > 0 && y > 0) {
            return 1;
        }

        if (x < 0 && y > 0) {
            return 2;
        }

        if (x < 0 && y < 0) {
            return 3;
        }

        if (x > 0 && y < 0) {
            return 4;
        }

        return 0;
    }

    double getDistance(double x1, double y1) const {
        return sqrt(pow((x - x1), 2) + pow(y - y1, 2));
    }

    double getDistance(const Point& obj) const {
        return getDistance(obj.getX(), obj.getY());
    }

    double getDistanceFromZero() const {
        return this->getDistance(0, 0);
    }

    void moveX(double value) {
        this->setY(y + value);
    }

    void moveY(double value) {
        this->setX(x + value);
    }

    friend ostream& operator<<(ostream& os, const Point& obj) {
        os << "(" << obj.x << ", " << obj.y << ")";
        return os;
    }

    friend istream &operator>>( istream  &input, Point &obj ) {
        input >> obj.x >> obj.y;
        return input;
    }

    friend bool operator==(const Point& obj1, const Point& obj2) {
        return obj1.x == obj2.x && obj1.y == obj2.y;
    }

    friend bool operator!=(const Point& obj1, const Point& obj2) {
        return !(obj1 == obj2);
    }
private:
    double x;
    double y;
};