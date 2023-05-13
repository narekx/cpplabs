#include <iostream>
//#include "Person.h"
#include "Driver.h"
#include "Helpers.h"
using namespace std;

#define N 6

void test1() {
    cout << "Start test1" << endl;
    Person p;
    cin >> p;
    cout << p;
    cout << p.getAge() << endl;
    Person p2("Narek", "Hovsepyan", "id", 2001);
    cout << p2 << endl;
    Driver d;
    cin >> d;
    cout << d;
    cout << d.getDriverExperience();
    cout << "End test1" << endl;
}
bool compareForTest2(Driver &d1, Driver &d2) {
    if (d1.getLicenseYear() < d2.getLicenseYear()) {
        return true;
    }

    if (d1.getLicenseYear() > d2.getLicenseYear()) {
        return false;
    }

    return d1.getBirthYear() > d2.getBirthYear();
}

void test2() {
    cout << "Start test2" << endl;
    Driver *arr = new Driver[N];
    for (int i = 0; i < N; i++) {
//        cin >> arr[i];
        arr[i] = Driver(
                randomString(5),
                randomString(5),
                randomString(5),
                random(1990, 2005),
                randomString(6),
                random(2015, 2020)
                );
    }
    cout << endl;

    quickSort<Driver>(arr, 0, N - 1, compareForTest2);

    cout << "====" << endl;
    cout << "Youngest driver with longest driver experience" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i].getDriverExperience() << ", " << arr[i].getAge() << endl;
    }
//    cout << arr[0];
    cout << endl;

    delete []arr;
    cout << "End test2" << endl;
}

int main() {
    test1();
//    test2();

    return 0;
}
