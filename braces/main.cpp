#include <iostream>
#include <string>
#include <stack>
using namespace std;

int checkValidation(string str) {
    stack<char> s;
    int count = 0;

    for (int i = 0; i< str.size(); i++) {
        if (str[i] == '<' || str[i] == '[' || str[i] == '{' || str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == '>' || str[i] == ']' || str[i] == '}' || str[i] == ')') {
            if (s.empty()) {
                return -1;
            }

            char top = s.top();
            if (
                (top == '<' && str[i] != '>')
                || (top == '(' && str[i] != ')')
                || (top == '{' && str[i] != '}')
                || (top == '[' && str[i] != ']')
            ) {
                count++;
            }
            s.pop();
        }
    }

    return count;
}

int main() {
    string a;
    cin >> a;
    cout << checkValidation(a) << endl;

    return 0;
}
