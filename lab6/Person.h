#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    string passportId;
    unsigned int birthYear;

    unsigned int getCurrentYear() const {
        time_t current_time;
        current_time = time(NULL);
        return 1970 + current_time / 31537970;
    }
public:
    Person() {
        this->setFirstName("");
        this->setLastName("");
        this->setPassportId("");
        this->setBirthYear(this->getCurrentYear());
    }

    Person(
        const string newFirstName,
        const string newLastName,
        const string newPassportId,
        const unsigned int newBirthYear
    ) {
        this->setFirstName(newFirstName);
        this->setLastName(newLastName);
        this->setPassportId(newPassportId);
        this->setBirthYear(newBirthYear);
    }

    Person(const Person &source) {
        this->firstName = source.firstName;
        this->lastName = source.lastName;
        this->passportId = source.passportId;
        this->birthYear = source.birthYear;
    }

    Person& operator =(const Person &t) {
        this->firstName = t.firstName;
        this->lastName = t.lastName;
        this->passportId = t.passportId;
        this->birthYear = t.birthYear;

        return *this;
    }

    void setFirstName(const string &value) {
        this->firstName = value;
    }

    string getFirstName() const {
        return this->firstName;
    }

    void setLastName(const string &value) {
        this->lastName = value;
    }

    string getLastName() const {
        return this->lastName;
    }

    void setPassportId(const string &value) {
        this->passportId = value;
    }

    string getPassportId() const {
        return this->passportId;
    }

    void setBirthYear(const unsigned int value) {
        this->birthYear = value;
    }

    unsigned int getBirthYear() const {
        return this->birthYear;
    }

    friend ostream &operator <<(ostream &os, const Person &source) {
        os << "First name: " << source.firstName << endl;
        os << "Last name: " << source.lastName << endl;
        os << "Id number: " << source.passportId << endl;
        os << "Birth year: " << source.birthYear << endl;
        return os;
    }

    friend istream &operator >>(istream &in, Person &source) {
        cout << "First name: ";
        in >> source.firstName;
        cout << "Last name: ";
        in >> source.lastName;
        cout << "Id number: ";
        in >> source.passportId;
        unsigned int newBirthYear;
        cout << "Birth year: ";
        in >> newBirthYear;
        source.setBirthYear(newBirthYear);
        return in;
    }

    unsigned int getAge() const {
        return this->getCurrentYear() - this->birthYear;
    }
};
