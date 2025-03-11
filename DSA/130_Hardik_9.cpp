#include <iostream>
using namespace std;

struct node{
    int id;
    string name;
    int num_people;
    string phone;
    node* next;
};

class RestaurantWaitlist{
    node* front;
    node* rear;

    public:
    RestaurantWaitlist(){
        front = NULL;
        rear = NULL;
    }

    bool is_empty(){
        return front == NULL;
    }

    void add_party(){
        node* new_node = new node;
        cout << "Enter the name: ";
        cin >> new_node -> name;
        cout << "Enter the number of people: ";
        cin >> new_node -> num_people;
        cout << "Enter the phone number: ";
        cin >> new_node -> phone;
        new_node -> next = NULL;

        if (is_empty()){
            front = rear = new_node;
        } else{
            rear -> next = new_node;
            rear = new_node;
        }
        
        assign_ids();
    }

    void seat_party(){
        if (is_empty()){
            cout << "Waitlist is empty, no party to seat." << endl;
            return;
        }
        
        node* to_delete = front;
        front = front -> next;

        if (front == NULL){
            rear = NULL;
        }

        delete to_delete;
        assign_ids();
    }

    void assign_ids(){
        node* temp = front;
        int position = 1;
        while (temp != NULL){
            temp -> id = position++;
            temp = temp -> next;
        }
    }

    void display_waitlist(){
        if (is_empty()){
            cout << "The waitlist is currently empty." << endl;
            return;
        }

        node* temp = front;
        cout << "--- Current Waitlist ---" << endl;
        while (temp != NULL){
            cout << "ID: " << temp -> id << " | ";
            cout << "Name: " << temp -> name << " | ";
            cout << "Phone: " << temp -> phone << " | ";
            cout << "Number of People: " << temp -> num_people << endl;
            temp = temp -> next;
        }
        cout << "-------------------------" << endl;
    }
};

int main(){
    RestaurantWaitlist waitlist;
    int choice;

    while (true){
        cout << "----- MENU -----" << endl;
        cout << "1: Add party to waitlist" << endl;
        cout << "2: Seat party" << endl;
        cout << "3: Display waitlist" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                waitlist.add_party();
                break;
            case 2:
                waitlist.seat_party();
                break;
            case 3:
                waitlist.display_waitlist();
                break;
            case 4:
                cout << "Leaving Restaurant!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
                break;
        }
    }

    return 0;
}
