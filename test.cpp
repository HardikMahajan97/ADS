#include<iostream>

#include<fstream>

#include<climits>


using namespace std;


class Queue{

	int *A;

	int s, front, rear;

	public:

	Queue(int size = 5){

		s = size;

		A = new int[s];

		front = rear = -1;

	}

	int isFull(){

		return rear == s - 1;

	}

	int isEmpty() {return front == -1;}

	void enQueue(int key){

		if(isEmpty()) front =  0;

		if(!isFull()) A[++rear] = key;
		return;
	}

	

	int deQueue(){

		if(isEmpty()) return INT_MIN;

		int e = A[front];

		if(front == rear)

			front = rear = -1;

		else

			front++;

		return e;

	}

};


class Graph{

	int **A;
	int v;
	public:
	Graph(string filename){

		fstream f;
		f.open(filename, ios::in);
		f>>v;
		cout<<"no of vertices = "<<v;
		A = new int*[v];
		if(!A) return;
		for(int i = 0; i < v; i++){
			A[i] = new int[v];
			for(int j = 0; j < v; j++) f>>A[i][j];
		}
		f.close();
    }

	void Display(){

		for(int i = 0; i < v; i++){
			cout<<endl;
			for(int j = 0; j < v; j++)
				cout<<A[i][j]<<"\t";
		}
		cout<<endl;
		return;	
	}

	void BFS(int sv){
		Queue Q;

		int *visited = new int[v];

		for(int i = 0; i <v; i++) visited[i] = 0;
		Q.enQueue(sv);
		visited[sv] = 1;
		int x;
		cout<<endl;
		while(!Q.isEmpty()){
			x = Q.deQueue();
			cout<<x<<"\t";
			for(int j = 0; j < v; j++){
				if(A[x][j]  && !visited[j]){
					Q.enQueue(j);
			    	visited[j] = 1;
				}
			}
		}
	}
};

int main(){

	Graph G("ADS\\matrix.txt");

	G.Display();

	G.BFS(0);

	return 0;

}
