#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct node{
    node* right;
    node* left;
    string word, meaning;
};

class BST{
    node *root;
    
    private:
    void inorder_2(node* root){
        if (!root) return;
        inorder_2(root->left);
        cout << root->word << ": " << root->meaning << endl;
        inorder_2(root->right);
    }
    
    node* deleteNode(node* root, string key){
        if (!root) return root;
        if (key < root->word) root->left = deleteNode(root->left, key);
        else if (key > root->word) root->right = deleteNode(root->right, key);
        else{
            if (!root->left){
                node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right){
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* succParent = root;
            node* succ = root->right;
            while (succ->left){
                succParent = succ;
                succ = succ->left;
            }
            root->word = succ->word;
            root->meaning = succ->meaning;
            root->right = deleteNode(root->right, succ->word);
        }
        return root;
    }
    
    node* mirror(node* root){
        if (!root) return NULL;
        node* temp = new node();
        temp->word = root->word;
        temp->meaning = root->meaning;
        temp->left = mirror(root->right);
        temp->right = mirror(root->left);
        return temp;
    }
    
    node* copyTree(node* root){
        if (!root) return nullptr;
        node* newNode = new node();
        newNode->word = root->word;
        newNode->meaning = root->meaning;
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);
        return newNode;
    }
    
    public:
    BST(){ 
        root = NULL; 
    }
    
    void insert(string word, string meaning){
        node* nn = new node();
        nn->left = NULL;
        nn->right = NULL;
        nn->word = word;
        nn->meaning = meaning;
        if (!root){
            root = nn;
            return;
        }
        node* ptr = root;
        while (ptr){
            if (ptr->word == word){
                delete nn;
                return;
            }
            if (ptr->word < word){
                if(!ptr->right){
                    ptr->right = nn;
                    return;
                }
                ptr = ptr->right;
            } else{
                if(!ptr->left){
                    ptr->left = nn;
                    return;
                }
                ptr = ptr->left;
            }
        }
    }
    
    string search(string word){
        node* ptr = root;
        while (ptr){
            if (ptr->word == word) return ptr->meaning;
            if (ptr->word < word) ptr = ptr->right;
            else ptr = ptr->left;
        }
        return "Word not found!";
    }
    
    void inorder(){ 
        inorder_2(root);
    }
    void deleteWord(string word){ 
        root = deleteNode(root, word); 
    }
    void mirrorImage(){
        root = mirror(root);
    }
    BST copyDictionary(){
        BST newDict;
        newDict.root = copyTree(root);
        return newDict;
    }
    void levelOrderTraversal(){
        if (!root) return;
        queue<node*> q;
        q.push(root);
        while (!q.empty()){
            node* temp = q.front(); q.pop();
            cout << temp->word << ": " << temp->meaning << endl;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
};

int main(){
    BST dict;
    dict.insert("scop", "an Old English bard or poet");
    dict.insert("striated", "marked with streaks or grooves");
    dict.insert("blitz", "a charge on the passer as soon as the ball is snapped");
    dict.insert("stilted", "unnaturally stiff, formal, or pompous");
    dict.insert("Bword", "Testing B word");
    
    cout << "Dictionary contents (inorder traversal):\n";
    dict.inorder();
    
    cout << "Enter a word to search: ";
    string word;
    cin >> word;
    cout << "Meaning: " << dict.search(word) << endl;
    
    cout << "\nDeleting 'scop' from dictionary.\n";
    dict.deleteWord("scop");
    cout << "\nDeleting 'Anything' from dictionary.\n";
    dict.deleteWord("Anything");
    dict.inorder();
    
    cout << "\nDisplaying dictionary level-wise:\n";
    dict.levelOrderTraversal();
    
    cout << "\nCreating and displaying a mirrored dictionary:\n";
    dict.mirrorImage();
    dict.inorder();
    
    cout << "\nCreating and displaying a copy of the dictionary:\n";
    BST copiedDict = dict.copyDictionary();
    copiedDict.inorder();
    
    return 0;
}
