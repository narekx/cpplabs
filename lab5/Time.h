#include <iostream>
#include <string>
using namespace std;

class Time {
protected:
    unsigned int hour;
    unsigned int minute;

    void setHour(unsigned int value) {
        if (value > 23) {
            value = 0;
        }

        this->hour = value;
    }

    void setMinute(unsigned int value) {
        if (value > 59) {
            value = 0;
        }

        this->minute = value;
    }

    void addHour() {
        if (this->hour == 23) {
            this->hour = 0;
        } else {
            this->hour++;
        }
    }

    void addMinute() {
        if (this->minute == 59) {
            this->minute = 0;
            this->addHour();
        } else {
            this->minute++;
        }
    }

    string getPaddedString(unsigned int number) const {
        string str = to_string(number);
        return string( (2 - str.size() ), '0').append(str);
    }

    string getSuffix() const {
        return this->hour > 11 ? "PM" : "AM";
    }

    unsigned int getHourFor12() const {
        return this->hour > 11 ? this->hour - 12 : this->hour;
    }

    string toString(const unsigned int hour, const unsigned int minute) const {
        return this->getPaddedString(hour) + ":" + this->getPaddedString(minute);
    }

    string toPrint() const {
        return this->toString(this->hour, this->minute);
    }

    string toPrint12() const {
        return this->toString(this->getHourFor12(), this->minute) + "[" + this->getSuffix() + "]";
    }
public:
    Time(unsigned int hour = 0, unsigned int minute = 0) {
        this->setHour(hour);
        this->setMinute(minute);
    }

    Time(Time &t) {
        this->hour = t.hour;
        this->minute = t.minute;
    }

    Time& operator =(const Time &t) {
        if (*this != t) {
            this->hour = t.hour;
            this->minute = t.minute;
        }

        return *this;
    }

    bool operator ==(const Time &t) const {
        return this->hour == t.hour && this->minute == t.minute;
    }

    bool operator !=(const Time &t) const {
        return !(*this == t);
    }

    bool operator >(const Time &t) const {
        return this->minuteNumber() > t.minuteNumber();
    }

    bool operator <(const Time &t) const {
        return this->minuteNumber() < t.minuteNumber();
    }

    Time& operator ++() {
        this->addMinute();
        return *this;
    }

    Time operator ++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    friend istream &operator >>(istream &in, Time &t) {
        unsigned int newHour;
        unsigned int newMinute;
        cout << "Enter hour: ";
        in >> newHour;
        t.setHour(newHour);

        cout << "Enter minute: ";
        in >> newMinute;
        t.setMinute(newMinute);

        return in;
    }

    friend ostream &operator <<(ostream &os, const Time &t) {
        os << t.toPrint();
        return os;
    }

    void print() {
        cout << this->toPrint() << endl;
    }

    void print12() {
        cout << this->toPrint12() << endl;
    }

    unsigned int minuteNumber() const {
        return this->hour * 60 + this->minute;
    }
};