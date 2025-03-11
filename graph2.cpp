#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

struct node {
	int s,e,w;
	node* next;
};

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
		if(front == rear) front = rear = -1;
		else front++;
		return e;
	}
};

class Graph{

	node **A;
	int v;
	public:
	Graph(string filename){

		fstream f;
		f.open(filename, ios::in);
		if(!f.is_open()) return;
		f>>v;
		cout<<"no of vertices = "<<v;
		A = new node*[v];
		if(!A) return;

		for(int i = 0; i < v; i++) A[i] = NULL;

		node *nn;
		int e;
		for(int i = 0; i < v; i++){
			A[i] = nullptr;
			for(int j = 0; j < v; j++){
				f >> e;
				if(e){
					nn = new node();
					if(!nn) return;
					nn -> s = i;
					nn -> e = j;
					nn -> w = e;
					nn -> next = A[i];
					A[i] = nn;
				}
			}
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
