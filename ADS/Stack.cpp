#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
    top = -1;
}

void Stack::push(int element) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack Overflow! Cannot push more elements.\n";
        return;
    }
    data[++top] = element;
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow! No elements to pop.\n";
        return -1;
    }
    return data[top--];
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return data[top];
}

bool Stack::isEmpty() {
    return (top < 0);
}
bool Stack::isFull() {
    return (top > MAX_SIZE - 1);
}