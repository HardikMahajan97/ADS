#include<iostream>
using namespace std;


struct node{
    int data;
    node* next;
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtFront(node* &head, int data);
void insertAtTail(node* &tail, int data);

void insertAtFront(node* &head, int data){
    // First Step: Assign the new node to temp;
    // For that create a new node
    // This thing stores the data because it calls the constructor there and then assigns the data to the particular class node.
    node* temp = new node(data);

    // Second Step : Now you need to connect it to the list right? So connect from the beginning...
    temp -> next = head;

    // Third Step : Now what about the orignal head? It should be the face of the list hai na! Then do it.
    head = temp;
}

void insertAtTail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtGivenPosition(node* &tail, node* &head, int position, int data){
    
    if(position == 1){
        insertAtFront(head, data);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    node* nodeToInsert = new node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void displayList(node* &head){
    // SO basically head is the strating point of the list. And if you start traversing from he head, you would reach the end of the list.
    // Now for that head should be assigned to some temp node so that that temp node would be able to do the operations of traversing.
    //This is because if you start traversing the head, then you would loose the face of the linked list and hence no list would exist.
    node *temp = head;
    
    while(temp != NULL){
        cout <<" -> "<< temp -> data;
        //Update the temp by pointing it to the next node.
        temp = temp -> next;
    }
}

int main(){
    node* head = new node(6);
    node* tail = new node(8);
    // cout<<"\nEnter the size of the list : "<<endl;
    // int size, value; 
    // cin>>size;
    // for(int i = 0; i < size; i++){
    //     cout<<"Enter value "<<i + 1<<" : "<<endl;
    //     cin >> value;
    //     insertAtFront(head, value);
    // }
    insertAtFront(head, 13);
    

    insertAtFront(head, 814);
    
    insertAtFront(head, 19);
    // displayList(head);

    insertAtTail(tail, 9);
    // displayList(tail);
    insertAtTail(tail, 10);
    // displayList(tail);
    insertAtTail(tail, 11);
    // displayList(tail);
    // insertAtTail(tail, 12);
    // displayList(tail);
    // insertAtTail(tail, 13);
    // displayList(head);
    // displayList(tail);
    insertAtGivenPosition(tail, head, 4 , 14);
    displayList(tail);
    cout<<"\nHead : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data   <<endl;
    return 0;
}