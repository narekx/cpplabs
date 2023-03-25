#include <iostream>
#include <cmath>
#include <ctime>
#include "Circle.h"
using namespace std;
#define N 10
#define PI 3.14159265359

double getRandomNumber(bool isAbs = false) {
    double number = rand() % 20 - 10;
    return isAbs ? abs(number) : number;
}

void test1() {
    cout << "Start test 1" << endl;
    Point p = {2, 0};;
    Circle c(p, 0);
    cout << c << endl;
    cout << "r = " << c.getR() << endl;
    Point coords = c.getCoords();
    cout << "(" << coords.x << ", " << coords.y << ")" << endl;
    Point p1 = {2, 0};;
    Circle c1(p1, 4);
    if (c == c1) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not equal" << endl;
    }

    if (c > c1) {
        cout << "First is greater" << endl;
    }
    else {
        cout << "Second is greater" << endl;
    }

    Point p2 = {1, 1};
    if (c.inCircle(p2)) {
        cout << "In circle" << endl;
    }
    else {
        cout << "Not in circle" << endl;
    }

    cout << "Cross: " << c.getCrossCount(c1) << endl;

    c.printTangent(p2);
    cout << endl;
    cout << "End test 1" << endl;
}

void test2() {
    cout << "Start test 2" << endl;
    int n;
    cin >> n;
    Circle* arr = new Circle[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        Point p = {getRandomNumber(), getRandomNumber()};
        arr[i].setProps(p, getRandomNumber(true));
        cout << arr[i];
    }
    cout << endl;

    cout << "Circles, which area is greater than " << n << endl;
    for (int i = 0; i < N; i++) {
        if (arr[i].area() > n) {
            cout << arr[i] << " ";
        }
    }

    delete []arr;
    cout << endl;
    cout << "End test 2" << endl;
}

void test3() {
    cout << "Start test 3" << endl;
    int n;
    Circle* arr = new Circle[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        Point p = {getRandomNumber(), getRandomNumber()};
        arr[i].setProps(p, getRandomNumber(true));
        cout << arr[i];
    }

    cout << endl;

    int index = -1;
    int max = 0;
    for (int i = 0; i < N; i++) {
        int localMax = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }

            if (arr[i].getCrossCount(arr[j]) == 1) {
                localMax++;
            }
        }

        if (max < localMax) {
            max = localMax;
            index = i;
        }
    }

    if (index != -1) {
        cout << "Circle with max touches " << arr[index] << endl;
    }
    else {
        cout << "There is no such circles with touches" << endl;
    }

    delete []arr;
    cout << endl;
    cout << "End test 3" << endl;
}

void test4() {
    cout << "Start test 4" << endl;
    int n;
    Circle* arr = new Circle[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        Point p = {getRandomNumber(), getRandomNumber()};
        arr[i].setProps(p, getRandomNumber(true));
        cout << arr[i];
    }

    cout << endl;

    int counts[N];
    int max = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }

            if (arr[i].getCrossCount(arr[j]) == 0 && arr[i].inCircle(arr[j].getCoords())) {
                count++;
            }
        }

        counts[i] = count;
        if (max < count) {
            max = count;
        }
    }

    if (max == 0) {
        cout << "There are no inner circles" << endl;
    } else {
        cout << "Circles with max inner circles " << max << endl;
        for (int i = 0; i < N; i++) {
            if (counts[i] == max) {
                cout << arr[i] << " ";
            }
        }
    }

    delete []arr;
    cout << endl;
    cout << "End test 4" << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}