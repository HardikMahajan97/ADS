#include <iostream>
#define maxsize 100
using namespace std;

class Queue{
    int arr[maxsize];
    int frontIndex, rearIndex;

public:
    Queue(){
        frontIndex = 0;
        rearIndex = 0;
    }

    void enqueue(int x){
        if (rearIndex == maxsize){
            cout << "Queue overflow\n";
            return;
        }
        arr[rearIndex++] = x;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
    }

    int front(){
        if (isEmpty()){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    int isEmpty(){
        return frontIndex == rearIndex;
    }

    int size(){
        return rearIndex - frontIndex;
    }
};

class Stack{
    Queue q1, q2;

public:
    void push(int x){
        q1.enqueue(x);
    }

    void pop(){
        if (q1.isEmpty()){
            cout << "Stack is empty\n";
            return;
        }

        while (q1.size() > 1){
            q2.enqueue(q1.front());
            q1.dequeue();
        }

        q1.dequeue();
    }

    int top(){
        if (q1.isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }

        while (q1.size() > 1){
            q2.enqueue(q1.front());
            q1.dequeue();
        }

        int topElem = q1.front();

        q2.enqueue(topElem);

        return topElem;
    }

    int isEmpty(){
        return q1.isEmpty();
    }
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    s.pop();
    cout << "Top element after another pop: " << s.top() << endl;
    s.pop();
    return 0;
}