#include <iostream>
#include <ctime>
#include "Linear.h"
using namespace std;

#define N 6

double randomNum() {
    return rand() % 20 - 10;
}

double getCross(const Linear &source1, const Linear &source2) {
    return (source2.getB() - source1.getB()) / (source1.getA() - source2.getB());
}

void test1() {
    srand(time(0));
    Linear *arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new Linear(randomNum(), randomNum());
        cout << *arr[i];
    }

    bool result = true;
    double crossX = NULL;
    for (int i = 0; i < N - 1; i++) {
        double cross = getCross(*arr[i], *arr[i + 1]);
        if (!crossX) {
            crossX = cross;
        }

        if (crossX != cross) {
            result = false;
            break;
        }
    }

    cout << (result ? "Yes" : "No") << endl;

    for (int i = 0; i < N; i++) {
        delete arr[i];
    }
}

void test2() {
    srand(time(0));
    double num;
    cout << "Input number: ";
    cin >> num;
    Linear *arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new Linear(randomNum(), randomNum());
        cout << *arr[i];
    }

    Linear *max = nullptr;
    for (int i = 0; i < N; i++) {
        if (!max || max->op(num) < arr[i]->op(num)) {
            max = arr[i];
        }
    }

    cout << "Maximum value has " << endl;
    cout << *max;

    for (int i = 0; i < N; i++) {
        delete arr[i];
    }
}

void test3() {
    srand(time(0));
    Linear *arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new Linear(randomNum(), randomNum());
        cout << arr[i]->def() << endl;
    }

    for (int i = 0; i < N; i++) {
        delete arr[i];
    }
}

int main() {
    test1();
//    test2();
//    test3();

    return 0;
}
