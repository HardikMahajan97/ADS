#ifndef STACK_H
#define STACK_H

class Stack {
private:
    static const int MAX_SIZE = 100;
    int top;
    int data[MAX_SIZE];

public:
    Stack();
    void push(int element);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};  

#endif // STACK_H
