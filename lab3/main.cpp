#include <iostream>
#include <cmath>
#include <ctime>
#include "Cylinder.h"
using namespace std;
#define N 10
#define PI 3.14159265359

double getRandomNumber() {
    return rand() % 20 + 1;
}

int Cylinder::objectCount = 0;

void test1() {
    cout << "Start test1" << endl;

    Cylinder c1;
    cout << "Radius: " << c1.getR() << endl;
    cout << "Height: " << c1.getH() << endl;
    cin>> c1;
    Cylinder c2(5, 6);
    cout << (c1 == c2 ? "Equal" : "Not equal") << endl;
    cout << (c1 < c2 ? "Second volume is greater" : "First volume is greater") << endl;
    cout << (c1 > c2 ? "First volume is greater" : "Second volume is greater") << endl;
    c1 = c2;
    cout << "Volume: " << c1.volume() << endl;
    cout << "baseArea: " << c1.baseArea() << endl;
    cout << "lateralArea: " << c1.lateralArea() << endl;
    cout << "surfaceArea: " << c1.surfaceArea() << endl;
    cout << "arancqayinArea: " << c1.arancqayinArea() << endl;
    cout << "Cylinders count" << Cylinder::getObjectCount() << endl;
    cout << "Multi volume: " << c1.multiVolume(5) << endl;

    cout << "End test1" << endl;
}

void test2() {
    cout << "Start test2" << endl;
    double num;
    cout << "Please enter number: ";
    cin >> num;

    Cylinder *arr = new Cylinder[N];

    srand(time(0));
    cout << "All cylinders" << endl;
    for (Cylinder *p = arr; p < arr + N; p++) {
        p->setProps(getRandomNumber(), getRandomNumber());
        cout << *p << " ";
    }
    cout << endl;

    cout << "Cylinders, which volume is less then " << num << endl;
    for (Cylinder *p = arr; p < arr + N; p++) {
        if (p->volume() < num) {
            cout << *p << " ";
        }
    }
    cout << endl;
    delete []arr;

    cout << "End test2" << endl;
}

int partition(Cylinder arr[], int low, int high)
{
    Cylinder *pivot = &arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].surfaceArea() > pivot->surfaceArea()) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Cylinder arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void test3() {
    cout << "Start test3" << endl;

    Cylinder *arr = new Cylinder[N];

    srand(time(0));
    cout << "All cylinders" << endl;
    for (Cylinder *p = arr; p < arr + N; p++) {
        p->setProps(getRandomNumber(), getRandomNumber());
        cout << *p << " ";
    }
    cout << endl;

//    bubble sort
//    for (Cylinder *p = arr; p < arr + N; p++) {
//        for (Cylinder *j = arr; j < arr + N; j++) {
//            if (p->surfaceArea() > j->surfaceArea()) {
//                Cylinder t;
//                t = *p;
//                *p = *j;
//                *j = t;
//            }
//        }
//    }

    quickSort(arr, 0, N - 1);

    cout << "Three cylinders with greatest surface areas" << endl;
    for (Cylinder *p = arr; p < arr + N; p++) {
        cout << p->surfaceArea() << " ";
    }
    cout << endl;
    delete []arr;

    cout << "End test3" << endl;
}

int main()
{
    test1();
    test2();
    test3();
}