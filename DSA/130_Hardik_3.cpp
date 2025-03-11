#include<iostream>
#include<string>
using namespace std;

struct Node{
    int songID;
    string title;
    struct Node *next;
};

class songList {
    Node* head;

public:
    songList(){
        head = NULL;
    }

    void showSong(Node* p){
        cout << p->songID << "\t" << p->title << endl;
    }

    void addSongs(int id, string stitle){
        Node* nn = new Node; // New is used to allocate memory.
        if(nn == NULL){
            cout << "Memory allocation failed!" << endl;
            return;
        }

        nn->next = NULL;
        nn->songID = id;
        nn->title = stitle;

        if(!head){
            head = nn;
            return;
        }

        Node* p = head;
        while(p->next){
            p = p->next;
        }
        p->next = nn;
    }

    void playAll(){
        if(head == NULL){
            cout << "No songs in the list!" << endl;
            return;
        }

        Node* p = head;
        while(p){
            showSong(p);
            p = p->next;
        }
    }

    void removeSong(string title){
        if(head == NULL){
            cout << "Empty song list!" << endl;
            return;
        }
        Node* p = head;
        Node* q = NULL;
        while(p){
            if(p->title == title){
                break;
            }
            q = p;
            p = p->next;
        }

        if(!p){
            cout << "Song not found!" << endl;
            return;
        }

        if(p == head){
            head = p->next;
            delete p;
        } else {
            q->next = p->next;
            delete p;
        }
        cout << "Song '" << title << "' removed!" << endl;
    }

    void searchAndPlaySong(string title){
        Node* temp = head;
        while(temp){
            if(temp->title == title){
                cout << "Now playing the song: " << temp->title << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found in the list!" << endl;
    }
};

int main(){
    songList l1;
    int numberOfSongs;
    int id = 0;
    string title;

    do{
        cout << "\nWhat operation do you want to perform?\n";
        cout << "1. Add songs\n";
        cout << "2. Delete song\n";
        cout << "3. Display all songs\n";
        cout << "4. Play a specific song\n";
        cout << "5. Exit\n";
        
        int choice;
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:
                cout << "Enter the number of songs: ";
                cin >> numberOfSongs;
                cin.ignore();
                for(int i = 0; i < numberOfSongs; i++){
                    cout << "Enter the song title: ";
                    getline(cin, title);
                    l1.addSongs(++id, title);
                }
                break;

            case 2:
                cout << "Enter the song you want to remove: ";
                cin.ignore();
                getline(cin, title);
                l1.removeSong(title);
                break;

            case 3:
                cout << "Displaying all songs:" << endl;
                l1.playAll();
                break;

            case 4:
                cout << "Enter the song title you want to play: ";
                cin.ignore();
                getline(cin, title);
                l1.searchAndPlaySong(title);
                break;

            case 5:
                cout << "Exiting the song app!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                return 0;
        }

        cout << "\nDo you want to perform another operation? [1]/[0]: ";
        int ch;
        cin >> ch;
        if(ch != 1){
            cout << "Exiting the program!" << endl;
            break;
        }
    } while(true);

    return 0;
}
