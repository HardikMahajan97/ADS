#include<iostream>
using namespace std;

struct node{
    int data;
    node* left, *right;
    int balance, height;
};

class AVL{
    node* root;
    
    void inorder(node* root){
        if(!root) return;

        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
        return;
    }

    int height(node* root){
        if(!root) return -1;

        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        return max(leftHeight, rightHeight) + 1;
    }

    int getBalanceFactor(node* temp){
        if(!temp) return 0;
        return height(temp -> left) - height(temp -> right);
    }

    // Right rotation
    node* RR(node* y){
        node* x = y -> left;
        node* T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        return x;
    }

    // Left rotation
    node* LL(node* x){
        node* y = x -> right;
        node* T2 = y -> left;

        y -> left = x;
        x -> right = T2;

        return y;
    }

    node* checkBalance(node* temp){
        if(!temp) return NULL;

        //First balance the children
        temp -> left = checkBalance(temp -> left);
        temp -> right = checkBalance(temp -> right);

        //Update height and balance factor
        temp -> height = height(temp);
        temp -> balance = getBalanceFactor(temp);

        // If node is unbalanced
        if(temp -> balance > 1){
            // Left-Left case
            if(getBalanceFactor(temp -> left) >= 0){
                return RR(temp);
            }
            // Left-Right case
            else{
                temp -> left = LL(temp -> left);
                return RR(temp);
            }
        }
        if(temp -> balance < -1){
            // Right-Right case
            if(getBalanceFactor(temp -> right) <= 0){
                return LL(temp);
            }
            // Right-Left case
            else{
                temp -> right = RR(temp -> right);
                return LL(temp);
            }
        }

        return temp;
    }

    public:
    AVL(){
        root = NULL;
    }

    void insert(int data){
        node* nn = new node();
        if(!nn) return;  //Checking Memory Allocation to the new node;

        nn -> data = data;
        nn -> left = NULL;
        nn -> right = NULL;

        if(!root){
            root = nn;
            return;
        }

        node* temp = root;
        //Insertion like BST;
        while(temp){
            //If node is found, return cuz, no duplicates allowed;
            if(temp -> data == data){
                delete nn;
                return;
            }
            //If new data is less than the current data, traverse to left;
            else if(temp -> data > data){
                if(!temp -> left){
                    temp -> left = nn;
                    break;
                }
                temp = temp -> left;
            }
            //Or else traverse to right;
            else{
                if(!temp -> right){
                    temp -> right = nn;
                    break;
                }
                temp = temp -> right;
            }
        }

        //recursively check and fix balance;
        root = checkBalance(root);

        cout << "Inserted: " << data << endl;
        cout << "Height of tree is: " << height(root) << endl;
        cout << "Balance factor of root is: " << getBalanceFactor(root) << endl;
    }

    void height(){
        cout << "Height: " << height(root) << endl;
    }

    void display(){
        inorder(root);
        cout << endl;
    }
};

int main(){
    AVL tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(1);
    tree.insert(7);
    tree.insert(40);
    tree.insert(50);

    cout << "\nDisplaying the data:" << endl;
    tree.display();

    cout << "Height of the tree:" << endl;
    tree.height();
    return 0;
}