#include <iostream>
#include "Stack.h"
#include "Pair.h"
#include <cmath>
#include <ctime>
using namespace std;

#define N 10

int getRandomNumber(bool isAbs = false) {
    double number = rand() % 20 - 10;
    return isAbs ? abs(number) : number;
}

void test1() {
    Stack <Pair> s(10);
    s.push(Pair{getRandomNumber(true), getRandomNumber(true)});
    s.push(Pair{getRandomNumber(true), getRandomNumber(true)});
    s.push(Pair{getRandomNumber(true), getRandomNumber(true)});
    cout << *s.pop() << endl;
    cout << *s.pop() << endl;
    if (!s.empty()) {
        s.print();
    }
}

void test2() {
    Stack <Pair> s1(10);
    Stack <Pair> s2(10);
    srand(time(0));
    for (int i = 0; i < N; i++) {
        s1.push(Pair{getRandomNumber(true), getRandomNumber(true)});
    }
    cout << "Initial numbers" << endl;
    s1.print();
    cout << endl;

    while (!s1.empty()) {
        Pair *p = s1.pop();
        if (p->isCoPrime()) {
            s2.push(*p);
        }
    }

    s2.print();

    cout << endl;
}

int main() {

    test1();
    test2();

    return 0;
}