#include <iostream>
#include <cmath>
#include <ctime>
#include "Point.h"
using namespace std;
#define N 10

double getRandomNumber() {
    return rand() % 20 - 10;
}


void test1() {
    cout << "Test 1 start" << endl;
    Point a(1, 5);
    cout << "x: " << a.getX() << endl;
    cout << "y: " << a.getY() << endl;
    cout << "distance from zero: " << a.getDistanceFromZero() << endl;
    cout << "a: " << a << endl;
    // cin>> a;
    Point b(2, 6);
    cout << "b: " << b << endl;
    cout << (a == b ? "equal" : "not equal") << endl;
    cout << "Test 1 end" << endl;
}

void test2() {
    cout << "Test 2 start" << endl;
    int num;
    cout << "Enter number: ";
    cin >> num;
    Point *arr = new Point[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i].setCoords(getRandomNumber(), getRandomNumber());
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Points, which distance from zero is less then " << num << endl;
    for (int i = 0; i < N; i++) {
        if (arr[i].getDistanceFromZero() < num) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    delete []arr;
    cout << "Test 2 end" << endl;
}

void test3() {
    cout << "Test 3 start" << endl;
    Point *arr = new Point[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i].setCoords(getRandomNumber(), getRandomNumber());
        cout << arr[i] << " ";
    }
    cout << endl;

    int coords[2] = {0, 1};
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if(arr[coords[0]].getDistance(arr[coords[1]]) < arr[i].getDistance(arr[j])) {
                coords[0] = i;
                coords[1] = j;
            }
        }
    }

    cout << "Longest distance have those points" << endl;
    cout << arr[coords[0]] << " " <<  arr[coords[1]]  << " = " <<
         arr[coords[0]].getDistance(arr[coords[1]]) <<  endl;

    delete []arr;
    cout << "Test 3 end" << endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}