#include<iostream>
using namespace std;

class Graph{
    int **arr;
    int size;
    int *deg;

    public:
    Graph(int s = 5){
        size = s;
        arr = new int*[size];  // Allocate memory for 'size' pointers to int (rows)
        int w = 0;
        deg = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = new int[size]; // Allocate memory for each row
            w = 0;  
            for(int j = 0; j < size; j++){
                cout << "Enter the weight at " << i << ", " << j << " th position: " << endl;
                int ch;
                cin >> ch;
                if(ch != 0) {
                    arr[i][j] = ch;
                    w++;
                } 
                else arr[i][j] = 0;

            }
            deg[i] = w;
        }
    }

    bool is_adjacent(int i, int j){
        return arr[i][j];
    }

    void isAdjacent(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << "is adjacent or not? " <<is_adjacent(i, j) << endl;
            }
        }
    }

    void display(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Degree of each vertex:" << endl;
        for(int i = 0; i < size; i++) cout << deg[i] << " ";
        cout << endl;
    }

};

// !Test comment on single comment
// test comment on single comment after shit ! loll doesn't work.
//TODO: Youhuuuuu nothing loll ADS study ig...

/*
* Main method
TODO: all the little little graph functions.
?What do you think? Should I do DSA?
!Alert: You should be doing it without fail idiot.abort.exception->Hardikers and other stuff in this file
*/
int main(){
    Graph g(5);

    g.display();

    g.isAdjacent();
    return 0;
}