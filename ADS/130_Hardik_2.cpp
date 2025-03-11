#include<iostream>
using namespace std;

struct Player{
    int pId;
    int score;
    Player *left, *right;
    int balance, height;
};

class GameSystem{
    Player* root;
    
    void inorder(Player* root){
        if(!root) return;

        inorder(root -> right);
        cout << "Player ID: " << root -> pId << " | Score: " << root -> score << endl;
        inorder(root -> left);
        return;
    }

    int getHeight(Player* root){
        if(!root) return -1;

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);

        return max(leftHeight, rightHeight) + 1;
    }

    int getBalanceFactor(Player* temp){
        if(!temp) return 0;

        return getHeight(temp -> left) - getHeight(temp -> right);
    }

    Player* RR(Player* y){
        Player* x = y -> left;
        Player* T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        return x;
    }

    Player* LL(Player* x){
        Player* y = x -> right;
        Player* T2 = y -> left;

        y -> left = x;
        x -> right = T2;

        return y;
    }

    Player* checkBalance(Player* temp){
        if(!temp) return NULL;

        temp -> left = checkBalance(temp -> left);
        temp -> right = checkBalance(temp -> right);

        temp -> height = getHeight(temp);
        temp -> balance = getBalanceFactor(temp);

        if(temp -> balance > 1){
            if(getBalanceFactor(temp -> left) >= 0){
                return RR(temp);
            }
            else{
                temp -> left = LL(temp -> left);
                return RR(temp);
            }
        }
        if(temp -> balance < -1){
            if(getBalanceFactor(temp -> right) <= 0){
                return LL(temp);
            }
            else{
                temp -> right = RR(temp -> right);
                return LL(temp);
            }
        }

        return temp;
    }

    Player* findMin(Player* node){
        Player* current = node;
        //Traverse to the left most node.
        while(current && current -> left != NULL)
            current = current -> left;
        return current;
    }

    Player* deleteNode(Player* root, int pId){
        if(!root) return root;

        if(pId < root -> pId)
            root -> left = deleteNode(root -> left, pId);
        else if(pId > root -> pId)
            root -> right = deleteNode(root -> right, pId);
        else{
            if(!root -> left || !root -> right){
                Player* temp = root -> left ? root -> left : root -> right;
                if(!temp){
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else{
                Player* temp = findMin(root -> right);
                root -> pId = temp -> pId;
                root -> score = temp -> score;
                root -> right = deleteNode(root -> right, temp -> pId);
            }
        }

        if(!root) return root;
        return checkBalance(root);
    }

    public:
    GameSystem(){
        root = NULL;
    }

    void registerPlayer(int pId, int initialScore = 0){
        Player* np = new Player();
        if(!np) return;

        np -> pId = pId;
        np -> score = initialScore;
        np -> left = NULL;
        np -> right = NULL;

        if(!root){
            root = np;
            cout << "Player " << pId << " registered successfully!" << endl;
            return;
        }

        //Insertion like BST.
        Player* temp = root;
        while(temp){
            //If duplicate found, return;
            if(temp -> pId == pId){
                cout << "Player " << pId << " already exists!" << endl;
                delete np;
                return;
            }
            //If given data is less then the current data, traverse to the left;
            else if(temp -> pId > pId){
                if(!temp -> left){
                    temp -> left = np;
                    break;
                }
                temp = temp -> left;
            }
            //Or else traverse right
            else{
                if(!temp -> right){
                    temp -> right = np;
                    break;
                }
                temp = temp -> right;
            }
        }

        
        root = checkBalance(root);
        cout << "Player " << pId << " registered successfully!" << endl;
    }

    void removePlayer(int pId){
        root = deleteNode(root, pId);
        cout << "Player " << pId << " removed from the game." << endl;
    }

    void displayLeaderboard(){
        cout << "\n=== LEADERBOARD ===" << endl;
        inorder(root);
        cout << "==================" << endl;
    }

    void updateScore(int pId, int newScore){
        Player* temp = root;
        while(temp){
            //Update if found
            if(temp -> pId == pId){
                temp -> score = newScore;
                cout << "Score updated for Player " << pId << ": " << newScore << endl;
                return;
            }
            //or else kep traversing right or left
            else if(temp -> pId > pId)
                temp = temp -> left;
            else
                temp = temp -> right;
        }
        cout << "Player " << pId << " not found!" << endl;
    }
};

int main(){
    GameSystem game;
    
    game.registerPlayer(101, 0);
    game.registerPlayer(102, 0);
    game.registerPlayer(103, 0);
    
    game.updateScore(101, 500);
    game.updateScore(102, 750);
    game.updateScore(103, 250);

    game.displayLeaderboard();
    game.removePlayer(102);
    game.displayLeaderboard();

    return 0;
}