//#include <iostream>
#include <cmath>
//#include "Time.h"
#include "TimeS.h"
#include "Helpers.h"
using namespace std;

#define N 7

void test1() {
    cout << "Start test1" << endl;

    Time t(14, 1);
    cin >> t;
    cout << t << endl;
    t.print12();
    cout << ++t << endl;
    cout << t++ << endl;
    t.print();

    TimeS ts(14, 14, 14);
    cout << ts << endl;
    t.toPrint12();

    cout << "End test1" << endl;
}

bool compareForTest2(Time &t1, Time &t2) {
    Time halfDay(12, 0);
    return abs((int)(t1.minuteNumber() - halfDay.minuteNumber())) < abs((int)(t2.minuteNumber() - halfDay.minuteNumber()));
}

void test2() {
    cout << "Start test2" << endl;
    Time *arr = new Time[N];
    for (int i = 0; i < N; i++) {
        arr[i] = *new Time(random(0, 23), random(0, 59));
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort<Time>(arr, 0, N, compareForTest2);

    cout << "Two closest times to 12:00" << endl;
    for (int i = 0; i < 2; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;
    cout << "End test2" << endl;
}

bool compareForTest3(TimeS &t1, TimeS &t2) {
    return t1 > t2;
}

void test3() {
    cout << "Start test3" << endl;
    TimeS *arr = new TimeS[N];
    for (int i = 0; i < N; i++) {
        arr[i] = *new TimeS(random(0, 23), random(0, 59));
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort<TimeS>(arr, 0, N, compareForTest3);

    cout << "Two longest times" << endl;
    for (int i = 0; i < 2; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;
    cout << "End test3" << endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
