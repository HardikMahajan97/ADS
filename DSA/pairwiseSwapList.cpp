#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};


class reverseLinkedList{
    node* head;
    node* tail;
    public:
    reverseLinkedList(){
        head = NULL;
        tail = NULL;
    }


    void insert(){
        node* nn = new node;
        cout << "Insert element " << endl;
        
        cin >> nn -> data;


        if(!head) {
            head = nn;
            head -> next = head;
            tail = head;
            return;
        }


        node* temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = nn;
        tail = nn;
        tail -> next = head;
    }


    void reverse(){
        node* temp = head;
        node* first = NULL;
        node* second = NULL;


        while(temp -> next != head){


            if(temp == head){
                first = temp -> next;
                second = first -> next;
                first -> next = temp;
                temp -> next = second;
                head = first;
                tail -> next = first;
                temp = temp -> next;


                cout << head -> data << endl;
                // return;
            }
            else if(temp -> next == tail){
                first = temp -> next;
                second = first -> next;
                temp -> next = second;
                first -> next = temp;
                tail = temp;
                temp = temp -> next;
            }
            else{
                first = temp -> next;
                second = first -> next;
                temp -> next = second;
                first -> next = temp;
                temp = temp -> next;


                cout << "running sir!"<<endl;
            }
            
        }


    }
    
    void display(){
        if(!head) return;


        node* temp = head;
        do{
            cout << temp -> data << "->";
            temp = temp -> next;
        }while(temp -> next != head);


        cout << temp -> data << endl;
        // cout << temp -> next -> data << endl;
    }


};




int main(){
    reverseLinkedList l;
    
    for(int i = 0; i < 5; i++) l.insert();
    cout << "Before reversing : " << endl;
    l.display();
    
    l.reverse();

    cout << "Hehe"<<endl;
    cout << "After reversing : " << endl;
    l.display();
    return 0;
}

