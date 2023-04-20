//#include <iostream>
//#include <string>
#include "Time.h"
//using namespace std;

class TimeS : Time {
private:
    unsigned int second;

    void setSecond(unsigned int value) {
        if (value > 59) {
            value = 0;
        }

        this->second = value;
    }

    void addSecond() {
        if (this->second == 59) {
            this->second = 0;
            this->addMinute();
        } else {
            this->second++;
        }
    }

    string toString(const unsigned int hour, const unsigned int minute, unsigned int second) const {
        return Time::toString(hour, minute)
        + ":"
        + this->getPaddedString(second);
    }

    string toPrint() const {
        return this->toString(this->hour, this->minute, this->second);
    }

    string toPrint12() const {
        return this->toString(this->getHourFor12(), this->minute, this->second) + "[" + this->getSuffix() + "]";
    }
public:
    TimeS(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0) : Time(hour, minute) {
        this->setSecond(second);
    }

    bool operator ==(const TimeS &t) const {
        return Time::operator==(t) && this->second == t.second;
    }

    bool operator !=(const TimeS &t) const {
        return !(*this == t);
    }

    bool operator >(const TimeS &t) const {
        return this->secondNumber() > t.secondNumber();
    }

    bool operator <(const TimeS &t) const {
        return this->secondNumber() < t.secondNumber();
    }

    TimeS& operator ++() {
        this->addSecond();
        return *this;
    }

    TimeS operator ++(int) {
        TimeS temp = *this;
        this->addSecond();
        return temp;
    }

    friend istream &operator >>(istream &in, TimeS &t) {
        unsigned int newHour;
        unsigned int newMinute;
        unsigned int newSecond;
        cout << "Enter hour: ";
        in >> newHour;
        t.setHour(newHour);

        cout << "Enter minute: ";
        in >> newMinute;
        t.setMinute(newMinute);

        cout << "Enter second: ";
        in >> newSecond;
        t.setSecond(newSecond);

        return in;
    }

    friend ostream &operator <<(ostream &os, const TimeS &t) {
        os << t.toPrint();
        return os;
    }

    unsigned int secondNumber() const {
        return Time::minuteNumber() * 60 + this->second;
    }
};