#include <iostream>
#include "Stack.h"
#include <cmath>
#include <ctime>
using namespace std;

#define N 10

int getRandomNumber(bool isAbs = false) {
    double number = rand() % 20 - 10;
    return isAbs ? abs(number) : number;
}

void test1() {
    Stack <int> s(10);
    s.push(5);
    s.push(6);
    s.push(2);
    s.push(4);
    cout << *s.pop() << endl;
    cout << *s.pop() << endl;
    if (!s.empty()) {
        s.print();
    }
}

int main() {

    test1();

    return 0;
}