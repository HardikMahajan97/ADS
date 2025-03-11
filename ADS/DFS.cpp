#include <iostream>
#include <fstream>
#include <climits>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
    int top;
    int data[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(int element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        data[++top] = element;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow! No elements to pop.\n";
            return -1;
        }
        return data[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return data[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

class DFS {
    int **A;
    int v;

public:
    DFS(string filename) {
        fstream f;
        f.open(filename, ios::in);
        f >> v;
        cout << "no of vertices = " << v;
        A = new int *[v];
        if (!A) return;
        for (int i = 0; i < v; i++) {
            A[i] = new int[v];
            for (int j = 0; j < v; j++) f >> A[i][j];
        }
        f.close();
    }

    void Display() {
        for (int i = 0; i < v; i++) {
            cout << endl;
            for (int j = 0; j < v; j++)
                cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    void depthFirstSearch() {
        Stack s;
        int *visited = new int[v];

        for (int i = 0; i < v; i++) visited[i] = 0;
        s.push(0);

        visited[0] = 1;
        cout << endl;
        while (!s.isEmpty()) {
            int x = s.peek();
            cout << "Visited: " << x << endl;

            bool found = false;
            for (int j = 0; j < v; j++) {
                if (A[x][j] && !visited[j]) {
                    s.push(j);
                    visited[j] = 1;
                    cout << "Print the element after making it visited: " << s.peek() << endl;
                    found = true;
                    break;
                }
            }
            if (!found) s.pop();
        }

        delete[] visited;
    }
};

int main() {
    DFS d("matrix.txt");

    d.Display();
    cout << "Depth First Search Alert" << endl;
    d.depthFirstSearch();

    // Stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // cout << s.isEmpty() << endl;

    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;

    // cout << s.isEmpty() << endl;

    return 0;
}
