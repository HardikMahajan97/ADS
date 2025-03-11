#include<iostream>
using namespace std;

struct node{
    node* next = NULL;
    node* previous = NULL;
    string word;
};
//TODO: Hello implement a better text buffer.
// *Important information is highlighted*
// !Should we use it?
// ? Lmao testing comments.
class textBuffer {
    node* head;
    node* tail;

public:
    textBuffer(){
        head = NULL;
        tail = NULL;
    }

    void insert(string word){
        node* nn = new node;
        
        nn->word = word;
        if(head == NULL){
            head = nn;
            tail = nn;
            return;
        }
        else{
            node* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
            nn->previous = temp;
            tail = nn;
            return;
        }
    }

    void deleteString(string toDelete){
        if(head == NULL) return;

        node* temp = head;

        // Delete at the first position in the list
        if(temp->word == toDelete){
            head = temp->next;
            if(head != NULL) head->previous = NULL;
            delete temp;
            return;
        }

        // Delete anywhere in the list
        while(temp && temp->word != toDelete){
            temp = temp->next;
        }
        
        if(temp == NULL) {
            cout << "Text not found!" << endl;
            return;
        }

        // Delete at the last position in the list
        if(temp->next == NULL){
            tail = temp->previous;
            temp->previous->next = NULL;
            delete temp;
            return;
        }

        // Delete at any other position
        temp->next->previous = temp->previous;
        temp->previous->next = temp->next;
        delete temp;
        return;
    }

    void search(string wordToFind){
        node* temp = head;
        int position = 0;
        bool found = false;

        while(temp != NULL){
            if(temp->word == wordToFind){
                found = true;
                cout << "Text '" << wordToFind << "' found at position: " << position << endl;
            }
            temp = temp->next;
            position++;
        }

        if(!found)
            cout << "Text '" << wordToFind << "' not found!" << endl;
    }

    void display(){
        node* temp = head;
        cout << "Displaying the List: " << endl;
        cout << "[ ";
        while(temp != NULL){
            cout << temp->word << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    void printReverse(){
        node* temp = tail;
        cout << "Displaying the List in Reverse: " << endl;
        cout << "[ ";
        while(temp != NULL){
            cout << temp->word << ", ";
            temp = temp->previous;
        }
        cout << "]" << endl;
    }
};

int main(){
    textBuffer t1;
    int choice;
    string word;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Insert Text" << endl;
        cout << "2. Delete Text" << endl;
        cout << "3. Display Text" << endl;
        cout << "4. Search Text" << endl;
        cout << "5. Print Text in Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter text to insert: ";
                cin >> word;
                t1.insert(word);
                break;

            case 2:
                cout << "Enter text to delete: ";
                cin >> word;
                t1.deleteString(word);
                break;

            case 3:
                t1.display();
                break;

            case 4:
                cout << "Enter text to search: ";
                cin >> word;
                t1.search(word);
                break;

            case 5:
                t1.printReverse();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again!" << endl;
                break;
        }
    } while(choice != 6);

    return 0;
}
