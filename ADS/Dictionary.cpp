#include<iostream>
#include<string.h>
using namespace std;

struct node{
    node* right;
    node* left;
    string word, meaning;
};

class BST{
    node *root = NULL;

    private:
    void inorder_2(node* root){
        if(!root){
            return;
        }

        inorder_2(root -> left);
        cout << root -> word << ": "<< root-> meaning << endl;
        inorder_2(root -> right);
        return;
    }


    public:
    BST(){
        root = NULL;
    }

    void insert(string word, string meaning){
        node* nn = new node();

        if(!nn) return;

        nn -> left = nn -> right = NULL;

        nn -> word = word;
        nn -> meaning = meaning;
        if(!root){
            root = nn; 
            return;
        }
        node* ptr = root;
        while(ptr){

            //case 1: If already exists.
            if(ptr -> word == word) {
                delete nn;
                return;
            }
            //If word is greater than root, go to right
            if(ptr -> word < word){
                if(!ptr -> right){
                    ptr -> right = nn;
                    return;
                }
                else{
                    ptr = ptr -> right;
                }
            }

            //If word is smaller than root, go to left
            if(ptr -> word > word){
                if(!ptr -> left){
                    ptr -> left = nn;
                    return;
                }
                else{
                    ptr = ptr -> left;
                }
            }
        }
        return;
    }

    string search(string word){

        if(!root){
            return "No root found";
        }
        node* ptr = root;
        while(ptr){
            //case 1: If already exists.
            if(ptr -> word == word) {
                string meaning = ptr -> meaning;
                return meaning;
            }
            //If word is greater than root, go to right
            if(ptr -> word < word){
                ptr = ptr -> right;
            }

            //If word is smaller than root, go to left
            if(ptr -> word > word){
                ptr = ptr -> left;
            }
        }
        cout<<"Word not found!"<<endl;
        return "Word not found!";
    }

    void inorder(){
        inorder_2(root);
    }
};

int main(){
    BST t1;
    t1.insert("Computer", "MachineToComputeSomething");
    t1.insert("Hardik", "My name");
    t1.insert("Sharvee", "My next roll number");
    t1.insert("Advi", "MyPartner currently");
    t1.insert("Bword", "testing B word");
    t1.insert("Advi", "MyPartner currently");

    t1.inorder();
    cout << "-------------" << endl;

    cout << "Enter what you want to search: " << endl;
    string word;
    cin >> word;
    cout << "Finding the word '" << word << "' in Dictionary : \n" << t1.search(word) << endl;
    return 0;
}