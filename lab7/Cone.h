#include "Shape3D.h"

class Cone: public Shape3D {
private:
    double radius;
    double height;
public:
    Cone(const double r = 0, const double h = 0) : Shape3D() {
        this->setRadius(r);
        this->setHeight(h);
    }

    Cone(const Cone &source) : Shape3D(source) {
        this->radius = source.radius;
        this->height = source.height;
    }

    Cone& operator =(const Shape3D &source) {
        return Cone::operator =(dynamic_cast<const Cone&>(source));
    }

    Cone& operator = (const Cone &source) {
        Shape3D::operator=(source);
        this->radius = source.radius;
        this->height = source.height;

        return *this;
    }

    void setRadius(double value) {
        if (value < 0) {
            value = 0;
        }

        this->radius = value;
    }

    void setHeight(double value) {
        if (value < 0) {
            value = 0;
        }

        this->height = value;
    }

    double getRadius() const {
        return this->radius;
    }

    double getHeight() const {
        return this->height;
    }

    double volume() const override {
        return PI * this->radius * this->radius * this->height / 3;
    }

    double surfaceArea() const override {
        return PI * this->radius * this->height;
    }

    void print() override {
        cout
            << "Cone[radius: " << this->radius
            << ", height: " << this->height
            << ", volume: " << this->volume()
            << ", surfaceArea: " << this->surfaceArea()
            << "]" << endl;
    }
};