#include<iostream>
using namespace std;

struct node{
    int route;
    node* next;
};

class list{
    node* head;
    node* tail;
    public:
    list(){
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int route){
        node* nn = new node;
        if(nn == NULL)
            return;
        nn -> route = route;

        if(!head){
            nn -> next = nn;
            head = nn;
            tail = nn;
        } else {
            nn -> next = head;
            tail -> next = nn;
            head = nn;
        }
    }

    void addEnd(int route){
        node* nn = new node;
        if(nn == NULL)  
            return;

        nn -> route = route;

        if(!head){
            head = nn;
            tail = nn;
            nn -> next = nn;
        } else {
            nn -> next = head;
            tail -> next = nn;
            tail = nn;
        }
    }

    void deleteFromBeginning(){
        if(!head){
            cout << "Empty list, add elements to the list." << endl;
            return;
        }
        if(head == tail){
            node* temp = head;
            head = tail = NULL;
            delete temp;
            cout << "Deleted the only node!" << endl;
            return;
        }
        node* temp = head;
        head = head -> next;
        tail -> next = head;
        delete temp;
        cout << "Element from beginning removed!" << endl;
    }

    void deleteFromTheEnd(){
        if(!head){
            cout << "Empty list!" << endl;
            return;
        }
        if(head == tail){
            node* temp = head;
            head = tail = NULL;
            delete temp;
            cout << "Deleted the only node!" << endl;
            return;
        }
        node* temp = head;
        node* prev = NULL;
        while(temp -> next != head){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = head;
        tail = prev;
        delete temp;
        cout << "Element from end removed!" << endl;
    }

    void search(int route){
        if(!head){
            cout << "Empty list" << endl;
            return;
        }
        node* temp = head;
        int count = 0;
        do {
            if(temp -> route == route){
                cout << "Element found at position: " << count << endl;
                return;
            }
            temp = temp -> next;
            count++;
        } while(temp != head);
                
        cout << "Element not found!" << endl;
    }

    void searchAndDelete(int route){
        if(!head){
            cout << "Empty list" << endl;
            return;
        }
        if(head -> route == route){
            deleteFromBeginning();
            return;
        }
        node* temp = head;
        node* prev = NULL;
        do {
            if(temp -> route == route){
                prev -> next = temp -> next;
                if(temp == tail) tail = prev;
                delete temp;
                cout << "Element " << route << " deleted from the list!" << endl;
                return;
            }
            prev = temp;
            temp = temp -> next;
        } while(temp != head);
                
        cout << "Element not found!" << endl;
    }

    void display(){
        if(!head){
            cout << "Empty list!" << endl;
            return;
        }
        node* temp = head;
        do {
            cout << temp -> route << " ";
            temp = temp -> next;
        } while(temp != head);
        cout << endl;
    }
};

void showMenu() {
    cout << "======= Circular Linked List Menu =======" << endl;
    cout << "1. Add Element at Beginning" << endl;
    cout << "2. Remove Element from Beginning" << endl;
    cout << "3. Add Element at End" << endl;
    cout << "4. Remove Element from End" << endl;
    cout << "5. Search for an Element" << endl;
    cout << "6. Search and Delete an Element" << endl;
    cout << "7. Display List" << endl;
    cout << "8. Exit" << endl;
    cout << "=========================================" << endl;
}

int main(){
    list l1;
    int choice, element;
    
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter the element to add at the beginning: ";
                cin >> element;
                l1.insertAtBeginning(element);
                break;
            case 2:
                l1.deleteFromBeginning();
                break;
            case 3:
                cout << "Enter the element to add at the end: ";
                cin >> element;
                l1.addEnd(element);
                break;
            case 4:
                l1.deleteFromTheEnd();
                break;
            case 5:
                cout << "Enter the element to search: ";
                cin >> element;
                l1.search(element);
                break;
            case 6:
                cout << "Enter the element to search and delete: ";
                cin >> element;
                l1.searchAndDelete(element);
                break;
            case 7:
                l1.display();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(choice != 8);

    return 0;
}
