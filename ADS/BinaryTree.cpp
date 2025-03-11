#include<iostream>

using namespace std;

struct node{
    int key;
    node *left, *right;
};

class BST{
    node *root;
    void inorder_rec(node *r){  
        if(!r) return;
        inorder_rec(r->left);
        cout<<r->key<<endl;
        inorder_rec(r->right);
        return;
    }
    public:
    BST(){
        root = NULL;
    }

    void add(int k) {
        node *nn = new node;    
        if(!nn)
            return;
        //put data in the nn
        nn->key = k;
    
        nn->left = nn->right = NULL;

        //empty tree?
        if(!root){
            root = nn;
            return;
        }


        node *ptr = root;
        while(ptr){
        if(ptr->key == k){
            delete nn;
            return;
        }
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
    }

    void inorder(){
        if(!root)
            return;
        inorder_rec(root);
        return;
    }
    node* find(int k){
        node *p = root, *pp = NULL;
        while(p){
            if(p->key == k)
                return pp;
            pp = p;
            if(p->key < k)
                p = p->right;
            else
                p = p->left;
        }
        return p;  
    }

    void removenode(int k){
        if(!root) return; //Tree is Empty.

        node* ptr = find(k); 
        if(!ptr) return; //Check if the element is present.

        
        node* cptr;
        if(ptr -> left -> key == k ){
            cptr = ptr -> left;
            if(!cptr->left && !cptr->right){ //Delete a leaf node;
                ptr -> left = NULL;
                delete cptr;
                return;
            }
            else if(!cptr -> left && cptr->right){ //something
                ptr -> left = cptr -> right;
                delete cptr;
                return;
            }
            else if(cptr -> left && !cptr->right){  // Only left child.
                ptr -> left = cptr -> left;  
                delete cptr;
                return;
            }
            else if(cptr -> left && cptr->right){  // both child.
                ptr -> left = cptr -> left;  
                node* r = cptr->right, *s = NULL;
                while(r -> left ){
                    s = r ;
                    r = r -> left;
                }
                cptr -> key = r ->key;
                s-> left = NULL;
                delete r;
                return;
            }
        }
        if(ptr -> right -> key == k){
            cptr = ptr -> right;
            if(!cptr->left && !cptr->right){
                ptr -> right = NULL;
                delete cptr;
                return;
            }
        }
        

    }
        
};


int main() {
    BST T1;

    T1.removenode(10);
    T1.add(25);
    T1.add(20);
    T1.add(36);
    T1.add(10);
    T1.add(22);
    T1.add(30);
    T1.add(40);
    T1.add(5);
    T1.add(12);
    T1.add(28);
    T1.add(38);
    T1.add(48);
    T1.add(1);
    T1.add(8);
    T1.add(11);
    T1.add(45);
    T1.add(50);
    T1.add(21);
    T1.inorder();

    cout << "Finding" << endl;
    cout <<  T1.find(50);

    //Deleting a leaf node
    T1.removenode(20);
    cout << "Deleting leaf node" << endl;
    T1.inorder();
    return 0;
}