#include <iostream>
#include "Cone.h"
#include "Sphere.h"
#include "Helpers.h"
using namespace std;

#define N 6

bool compareForTest1(Sphere &a, Sphere &b) {
    return a.getRadius() < b.getRadius();
}

void test1() {
    cout << "Start test1" << endl;
    Sphere *arr = new Sphere[N];
    for (int i = 0; i < N; i++) {
        arr[i] = Sphere(random(1, 30));
    }

    quickSort(arr, 0, N - 1, compareForTest1);

    for (int i = 0; i < N; i++) {
        arr[i].print();
    }

    delete []arr;
    cout << "End test1" << endl;
}

void test2() {
    cout << "Start test2" << endl;
    Shape3D *arr[N];
    for (int i = 0; i < N; i++) {
        if ((i % 2 == 0)) {
            arr[i] = new Sphere(random(1, 40));
        } else {
            arr[i] = new Cone(random(1, 40), random(1, 50));
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i]->volume() << " ";
    }

    cout << endl;

    cout << "End test2" << endl;
}

bool compareForTest3(Shape3D &a, Shape3D &b) {
    if (a.volume() > b.volume()) {
        return true;
    }

    if (a.volume() < b.volume()) {
        return false;
    }

    return a.surfaceArea() < b.surfaceArea();
}

void test3() {
    cout << "Start test3" << endl;
    Shape3D *arr[N];
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            arr[i] = new Sphere(random(1, 10));
        } else {
            arr[i] = new Cone(random(1, 40), random(1, 30));
        }
        arr[i]->print();
    }

    int t = findInArray(arr, 0, N, compareForTest3);
    arr[t]->print();

    cout << endl;

    cout << "End test3" << endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
