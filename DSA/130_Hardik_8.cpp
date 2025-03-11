#include <iostream>
#include <cstring>
using namespace std;

class CharStack {
    int top;
    int capacity;
    char* arr;

public:
    CharStack(int size) {
        top = -1;
        capacity = size;
        arr = new char[size];
    }

    void push(char value) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

class IntStack {
    int top;
    int capacity;
    int* arr;

public:
    IntStack(int size) {
        top = -1;
        capacity = size;
        arr = new int[size];
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    CharStack s(strlen(infix)); 
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isdigit(c)) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            s.push(c);
        }

        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }

        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; 
}

int evaluatePostfix(const char* postfix) {
    IntStack s(strlen(postfix)); 

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            s.push(c - '0'); 
        }

        else {
            int val2 = s.pop();
            int val1 = s.pop();
            
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.pop(); 
}

int main() {
    char infix[50], postfix[50];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
