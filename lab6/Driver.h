#include "Person.h"


class Driver : public Person{
private:
    string licenseId;
    unsigned int licenseYear;
public:
    Driver(): Person() {
        this->setLicenseId("");
        this->setLicenseYear(this->getCurrentYear());
    }

    Driver(
        const string newFirstName,
        const string newLastName,
        const string newPassportId,
        const unsigned int newBirthYear,
        const string newDriverId,
        const unsigned int newLicenseYear
    ): Person(newFirstName, newLastName, newPassportId, newBirthYear) {
        this->setLicenseId(newDriverId);
        this->setLicenseYear(newLicenseYear);
    }

    Driver(const Driver &source): Person(source) {
        this->licenseId = source.licenseId;
        this->licenseYear = source.licenseYear;
    }

    Driver& operator =(const Driver &source) {
        Person::operator=(source);
        this->licenseId = source.licenseId;
        this->licenseYear = source.licenseYear;

        return *this;
    }

    void setLicenseId(const string &value) {
        this->licenseId = value;
    }

    string getLicenseId() const {
        return this->licenseId;
    }

    void setLicenseYear(const unsigned int value) {
        this->licenseYear = value;
    }

    unsigned int getLicenseYear() const {
        return this->licenseYear;
    }

    friend ostream &operator <<(ostream &os, Driver &source) {
        os << static_cast<Person&>(source);
        os << "Id driver: " << source.licenseId << endl;
        os << "License year: " << source.licenseYear << endl;
        return os;
    }

    friend istream &operator >>(istream &in, Driver &source) {
        in >> static_cast<Person&>(source);
        cout << "Id driver: ";
        in >> source.licenseId;
        unsigned int newLicenseYear;
        cout << "License year: ";
        in >> newLicenseYear;
        source.setBirthYear(newLicenseYear);
        return in;
    }

    unsigned int getDriverExperience() const {
        return this->getCurrentYear() - this->licenseYear;
    }
};
