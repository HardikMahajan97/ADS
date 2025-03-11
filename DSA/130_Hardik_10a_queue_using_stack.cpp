#include <iostream>
#define maxsize 100
using namespace std;

class Stack{
    int arr[maxsize];
    int top;

public:
    Stack(){ top = -1; }

    int isEmpty(){
        return top == -1;
    }

    int isFull(){
        return top == maxsize - 1;
    }

    void push(int x){
        if (isFull()){
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        top--;
    }

    int peek(){
        if (isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

class Queue{
    Stack s1, s2;

    public:
    void enqueue(int x){
        if (s1.isFull()){
            cout << "Queue overflow\n";
            return;
        }
        s1.push(x);
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue underflow\n";
            return;
        }

        if (s2.isEmpty()){
            while (!s1.isEmpty()){
                s2.push(s1.peek());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front(){
        if (isEmpty()){
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.isEmpty()){
            while (!s1.isEmpty()){
                s2.push(s1.peek());
                s1.pop();
            }
        }
        return s2.peek();
    }

    int isEmpty(){
        return s1.isEmpty() && s2.isEmpty();
    }
};

int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element is: " << q.front() << endl; 

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl; 

    q.dequeue();
    q.dequeue();
    cout << "Front element after dequeing: " << endl;
    cout << q.front() << endl;


    return 0;
}
