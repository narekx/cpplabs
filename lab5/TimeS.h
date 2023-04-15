#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

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
        return this->getPaddedString(hour)
        + ":"
        + this->getPaddedString(minute)
        + ":"
        + this->getPaddedString(second);
    }

    string toPrint() const {
        return this->toString(this->hour, this->minute, this->minute);
    }

    string toPrint12() const {
        return this->toString(this->getHourFor12(), this->minute, this->second) + "[" + this->getSuffix() + "]";
    }
public:
    TimeS(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0) : Time(hour, minute) {
        this->setSecond(second);
    }

    bool operator ==(const TimeS &t) const {
        return this->hour == t.hour && this->minute == t.minute && this->second == t.second;
    }

    bool operator !=(const TimeS &t) const {
        return !(*this == t);
    }

    bool operator >(const TimeS &t) const {
        return this->secondNumber() > t.secondNumber();
//        if (this->hour < t.hour) {
//            return false;
//        }
//
//        if (this->hour > t.hour) {
//            return true;
//        }
//
//        if (this->minute < t.minute) {
//            return false;
//        }
//
//        if (this->minute > t.minute) {
//            return true;
//        }
//
//        return  this->second == t.second;
    }

    bool operator <(const TimeS &t) const {
        return this->secondNumber() < t.secondNumber();
//        return *this != t && !(*this > t);
    }

    TimeS operator ++() {
        this->addSecond();
        return *this;
    }

    TimeS operator ++(int) {
        TimeS temp = *this;
        this->addSecond();
        return temp;
    }

    friend ostream &operator <<(ostream &os, const TimeS &t) {
        os << t.toPrint();
        return os;
    }

    unsigned int secondNumber() const {
        return this->hour * 3600 + this->minute * 60 + this->second;
    }
};