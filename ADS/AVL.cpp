#include<iostream>
using namespace std;

struct node{
    int key, balance;
    node *left, *right, *parent;
    int height;
};

class AVL{
    node* root;
    void inorder_rec(node *r){  
        if(!r) return;
        inorder_rec(r->left);
        cout<<r->key<<endl;
        inorder_rec(r->right);
        return;
    }


    public:
    AVL(){
        root = NULL;
        root -> height = 0;
    }

    void insert(int k){
        node *nn = new node;    
        if(!nn)
            return;

        nn->key = k;
        nn->left = nn->right = NULL;

        //empty tree?
        if(!root){
            root = nn;
            return;
        }
    
        node *ptr = root;

        while(ptr){
        if(ptr->key == k)
                return;
        if(ptr->key < k){
            if(! ptr->right){
                ptr->right = nn;
                return;
            }
            ptr = ptr->right;
        }
        else{
            if(! ptr->left){
                ptr->left = nn;
                return;
            }
            ptr = ptr->left;
            }
        }
        //Get balance factor

    }


    int height(node *root) {
        if (!root) return -1;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
            
    void inorder(){
        if(!root)
            return;
        inorder_rec(root);
        return;
    }
};

int main(){
    AVL a;
    a.insert(25);
    a.insert(20);
    a.insert(36);
    a.insert(10);
    a.insert(22);
    a.insert(30);
    a.insert(40);
    a.insert(5);
    a.insert(12);
    a.insert(28);
    a.insert(38);
    a.insert(48);

    a.inorder();
    return 0;
}