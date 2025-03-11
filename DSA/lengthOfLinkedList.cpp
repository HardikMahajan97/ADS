#include<iostream>
using namespace std;
class node{
    node* head = NULL;
    node* tail = NULL;
    public:
    int data;
    node* next;
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }


    void insertAtTail(int data){
        node* new_node = new node(data);

        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        
        tail -> next = new_node;
        tail = new_node;
        return;
        
    }

    void countLengthOfList(){
        int count = 0;
        node* temp = head;
        if(head == NULL){
            cout<<"Empty List!"<<endl;
            return ;
        }
        while(temp){
            temp = temp -> next;
            count++;
        }
        cout<<"\nLength of the list is " << count <<endl;
    }

    void displayList(){
        node* temp = head;
        while(temp){
            cout<<" -> "<<temp -> data;
            temp = temp -> next;
        }
    }
};

int main(){
    node n1(8);

    n1.insertAtTail(1);
    n1.insertAtTail(2);
    n1.insertAtTail(3);
    n1.insertAtTail(4);
    n1.insertAtTail(5);
    n1.insertAtTail(7);
    n1.insertAtTail(6);
    n1.displayList();
    //Length of the list :
    n1.countLengthOfList();
    return 0;

}