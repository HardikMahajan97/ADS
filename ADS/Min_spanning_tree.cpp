#include<iostream>
#include<fstream>
#include<climits>
using namespace std;


struct edge{
    int s, e, w;
    edge* min;
    edge(){
        min -> s = 0;
        min -> e = 0;
        min -> w = INT_MAX;
    }
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

		return rear == s -1;

	}

	int isEmpty(){

		return front == -1;

	}

	void enQueue(int key){

	        if(isEmpty())

	        	front =  0;

	        

		if(!isFull())

			A[++rear] = key;

		

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



struct node {

	int s, e, w;

	node *next;

};



class Graph{

	node **A;

	int v;

	public:

	Graph(string filename){

		fstream fin;

		fin.open(filename, ios::in);

		if(!fin) return;

		fin>>v;

		cout<<"no of vertices = "<<v;

		A = new node*[v];

		if(!A) return;

		//ptr shd be NULL

		node *nn;

		int e;

		for(int i = 0; i < v; i++)

			A[i] = NULL;

		for(int i = 0; i < v; i++){

			for(int j = 0; j < v; j++){

				fin>>e;

				if(e){

					nn = new node;

					if(!nn) return;

					nn->s = i;

					nn->e = j;

					nn->w = e;

					nn->next = A[i];

					A[i] = nn;

					

				}

			}

		}

		fin.close();

	

	}

	void Display(){

	node *p;

		for(int i = 0; i < v; i++){

			cout<<"i = "<<i<<endl;;

			p = A[i];

			while(p){

				cout<<p->s<<"\t"<< p->e<<"\t"<<p->w<<"\n";

				p = p->next;

			}

			cout<<endl;

				

		}

		return;

	}

	

	

	void BFS(int sv){

		Queue Q;

		int *visited = new int[v];

		for(int i = 0; i < v; i++)

			visited[i] = 0;

		

		Q.enQueue(sv);

		visited[sv] = 1;

		int x;

		cout<<endl;

		node *p;

		while(!Q.isEmpty()){

			x = Q.deQueue();

			//cout<<x<<"\t";

			 p = A[x];

			 //cout<<"\n"<<p->e<<endl;

			 while(p){

			 	if(!visited[p->e]){

			 		cout<<p->e<<"\t";

					Q.enQueue(p->e);

					visited[p->e] = 1;

					

				}

				p = p->next;

			}

			

		}

		return;

	}



};

int main(){

	Graph G("matrix.txt");

	cout<<"\nGraph edges\n";

	G.Display();

	cout<<"\nBFS\n";

	G.BFS(0);

	return 0;

}