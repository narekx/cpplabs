#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
    int top = -1;
    int count = 0;
    T *arr;

    void copyValues(const Stack& obj) {
        delete []arr;
        arr = new T[obj.count];

        if (!obj(empty())) {
            for (int i = 0; i <= obj.top; i++) {
                arr[i] = obj.arr[i];
            }
        }
    }
public:
    Stack(int n = 10) {
        arr = new T[n];
        count = n;
    }

    Stack(const Stack &obj) {
        top = obj.top;
        count = obj.count;
        copyValues(obj);
    }

    ~Stack() {
        delete []arr;
    }

    bool push(T value) {
        if (full()) {
            cout << "Stack underflow" << endl;
            return false;
        }

        top++;
        arr[top] = value;
        return true;
    }

    T* pop() {
        if (empty()) {
            cout << "Stack underflow" << endl;
            return nullptr;
        }

        top--;
        return &arr[top + 1];
    }

    bool empty() const {
        return top == -1;
    }

    bool full() const {
        return top == count - 1;
    }

    Stack& operator=(const Stack& obj) {
        if (*this != obj) {
            top = obj.top;
            count = obj.count;
            copyValues(obj);
        }

        return *this;
    }

    bool operator==(const Stack& obj) const {
        if (count != obj.count) {
            return false;
        }

        if (top != obj.top) {
            return false;
        }

        for (int i = 0; i <= top; i++) {
            if (arr[i] != obj.arr[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Stack& obj) const {
        return !(*this == obj);
    }

    void print() {
        if (!empty()) {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};