#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int num1 = 0;
    int num2 = 0;

    Pair(int a = 0, int b = 0) {
        num1 = a;
        num2 = b;
    }

    friend ostream& operator<<(ostream &os, const Pair &obj) {
        cout << "(" << obj.num1 << ", " << obj.num2 << ")";
        return os;
    }

    bool isCoPrime() const {
        return __gcd(num1, num2) == 1;
    }
};