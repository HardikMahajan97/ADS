#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

class ll{
    node* head;
    public:
    ll(){
        head = NULL;
    }

    void insert(int data){
        node* nn = new node();
        nn -> data = data;
        if(!head){
            head = nn;
            return;
        }
        node* temp = head;
        while(temp -> next){
            temp = temp -> next;
        }

        temp -> next = nn;
        temp = nn;

    }

    node* aroundX(int x){
        node* less;
        node* great;

        node* lessHead = NULL;
        node* greatHead = NULL;

        node* temp = head;

        while(temp){
            cout << "Check";
            less = new node();
            great = new node();

            if(temp -> data < x){
                //Insertion in 'less' Linked list
                less -> data = temp -> data;
                if(!lessHead) lessHead = less;

                node* lessTemp = lessHead;
                while(lessTemp -> next){
                    lessTemp = lessTemp -> next;
                }

                lessTemp -> next = less;
                lessTemp = less;
            }
            else{
                //Insertion in 'great' linked list.
                great -> data = temp -> data;
                //Base case
                if(!greatHead) greatHead = great;
                
                node* greatTemp = greatHead;
                while(greatTemp -> next){
                    greatTemp = greatTemp -> next;
                }

                greatTemp -> next = great;
                greatTemp = great;
            }
            temp = temp -> next;
        }

        node* lessTemp = lessHead;

        while(lessTemp -> next){
            cout << "Check";
            lessTemp = lessTemp -> next;
        }
        lessTemp -> next = greatHead;

        return lessHead;
    }

     // Delete a node with a specific value
    void remove(int value) {
        if (head == nullptr) return; // List is empty

        // If the head node holds the value
        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse the list to find the node to delete
        node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // If the value was found, delete the node
        if (current->next != nullptr) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Print the list
    void printList() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main(){
    ll l;
    l.insert(1);
    l.insert(2);
    l.insert(7);
    l.insert(6);
    l.insert(5);
    l.insert(3);
    l.insert(4);
    cout << "Displaying ll:" << endl;
    l.printList();

    node* head = l.aroundX(4);

    node* temp =  head;
    while(temp -> next){
        cout << temp -> data << " ->";
        temp = temp -> next;
    }
    cout << temp -> data << endl;

    return 0;

}
