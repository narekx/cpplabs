#include "Shape3D.h"

class Sphere: public Shape3D {
private:
    double radius;
public:
    Sphere(const double r = 0) : Shape3D() {
        this->setRadius(r);
    }

    Sphere(const Sphere &source) : Shape3D(source) {
        this->radius = source.radius;
    }

    Sphere& operator =(const Shape3D &source) {
        return Sphere::operator =(dynamic_cast<const Sphere&>(source));
    }

    Sphere& operator = (const Sphere &source) {
        Shape3D::operator=(source);
        this->radius = source.radius;

        return *this;
    }

    void setRadius(double value) {
        if (value < 0) {
            value = 0;
        }

        this->radius = value;
    }

    double getRadius() const {
        return this->radius;
    }

    double volume() const override {
        return 4 * PI * this->radius * this->radius * this->radius / 3;
    }

    double surfaceArea() const override {
        return 4 * PI * this->radius * this->radius;
    }

    void print() override {
        cout
            << "Sphere[radius: " << this->radius
            << ", volume: " << this->volume()
            << ", surfaceArea: " << this->surfaceArea()
            << "]" << endl;
    }
};