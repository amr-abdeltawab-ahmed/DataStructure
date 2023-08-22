#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

string infixToPostfix(string exp) {
    Stack<char> stk;
    string result;
    for (int i = 0; i < exp.length(); i++) {
        if (isalnum(exp[i])) {
            result += exp[i];
        } else if (exp[i] == '(') {
            stk.push(exp[i]);
        } else if (exp[i] == ')') {
            while (!stk.isEmpty() && stk.top() != '(') {
                result += stk.pop();
            }
            if (!stk.isEmpty() && stk.top() != '(') {
                return "Invalid Expression";
            } else {
                stk.pop();
            }
        } else {
            while (!stk.isEmpty() && precedence(exp[i]) <= precedence(stk.top())) {
                result += stk.pop();
            }
            stk.push(exp[i]);
        }
    }
    while (!stk.isEmpty()) {
        result += stk.pop();
    }
    return result;
}

int main() {
    string infixExp, postfixExp;
    cout << "Enter the infix expression: ";
    getline(cin, infixExp);
    postfixExp = infixToPostfix(infixExp);
    cout << "The postfix expression is: " << postfixExp << endl;
    return 0;
}
