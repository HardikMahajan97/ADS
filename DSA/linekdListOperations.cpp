#include<iostream>
using namespace std;


struct node{
    node* next = NULL;
    node* previous = NULL;
    string word;
};

class textBuffer{
    node* head ;
    node* tail;
    public:
    textBuffer(){
        head = NULL;
        tail = NULL;
    }
    void insert(string word){
        node* nn = new node;
        nn -> word = word;
        if(head == NULL){
            head = nn;
            tail = nn;
            return;
        }
        else{
            node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = nn;
            nn -> previous = temp;
            tail = nn;
            //cout<< temp -> word;
            return;
        }
    }
    void deleteString(string toDelete){
        //Return if there is an empty list
        if(head == NULL) return;
        node* temp = head;
        //Delete at the first position in the list
        if(temp -> word == toDelete ){
            head = temp -> next;
            temp -> previous = NULL;
            delete temp;
            return;
        }
        //Delete anywhere in the list
        while(temp -> word != toDelete){
            temp = temp -> next;
        }
        //Delete at the last position in the list.
        if(temp -> next == NULL){
            tail = temp -> previous;
            temp -> previous -> next = NULL;
            delete temp;
            return;
        }


        //Delete at any other position.
        temp -> next -> previous = temp -> previous;
        temp -> previous -> next = temp -> next;
        delete temp;
        return;


    }


    void display(){
        node* temp = head;
        cout<<"Displaying the List :"<<endl;
        cout<<"[ ";
        while(temp != NULL){
            cout<< temp -> word<<", ";
            temp = temp -> next;
        }
        cout<<"]"<<endl;
        return;
    }

};


int main(){
    textBuffer t1;
    t1.insert("Hardik");
    t1.insert("Om");
    t1.insert("Shreeyash");
    t1.insert("Aditya");
    t1.insert("Aadi");
    t1.insert("Pratik");
    t1.insert("Saksham");
    t1.insert("Kunal");
    t1.insert("Ananaya");
    t1.insert("Karan");
    t1.display();
    cout<<"\n\nAfter deleting the element:"<<endl;
    t1.deleteString("Karan");
    t1.display();
    cout<<"\n\n";
    return 0;
}

