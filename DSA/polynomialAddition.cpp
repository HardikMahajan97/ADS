#include<iostream>
using namespace std;

struct node{
    int coeff;
    int power;
    node* next = NULL;
};

class polynomial{
    node* head;
    public: 
    polynomial(){
        head = NULL;
    }

    void insert(int coe, int exp){
        node* curr = new node();
        curr -> coeff = coe;
        curr -> power = exp;

        node* temp = head;
        if(!head){
            head = curr;
            return;
        }

        if(exp > head -> power){
            curr -> next = head;
            head = curr;
        }else{
            while(temp -> next && temp -> next -> power > exp){
                temp = temp -> next;
            }
            if (temp->power == exp) {
            temp->coeff += coe;
            } else {
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        return;
    }

    polynomial operator+(polynomial& p){
        polynomial result;
        if(!head || !p.head){
            cout << "ERROR: Empty Polynomials! Give both the polynomials" << endl;
            return result;
        }

        node* p1 = head;
        node* p2 = p.head;
        
        while(p1 && p2){ 
            if(p1 -> power > p2 -> power){
                result.insert(p1 -> coeff, p1 -> power);
                p1 = p1 -> next;
            }
            else if(p2 -> power > p1 -> power){
                result.insert(p2 -> coeff, p2 -> power);
                p2 = p2 -> next;
            }
            else{
                result.insert(p1 -> coeff + p2 -> coeff, p1 -> power);
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
        }

        while(p1){
            result.insert(p1 -> coeff, p1 -> power);
            p1 = p1 -> next;
        }
        while(p2){
            result.insert(p2 -> coeff, p2 -> power);
            p2 = p2 -> next;
        }

        return result;
    }

    void display(){
        if(!head){
            cout << "NO head"<< endl;
            return;
        }
        node* temp = head;
        while(temp -> next){
            cout << temp -> coeff << "x^" <<temp -> power << " -> ";
            temp = temp -> next;
        }
        cout <<  temp -> coeff << "x^" <<temp -> power << endl;

        return;
    }

};


int main(){
    polynomial p1;
    polynomial p2;
    polynomial p3;
    cout<<"Enter in list 1:"<<endl;
    p1.insert(3,4);
    p1.insert(5,6);
    p1.insert(2,6);
    p1.insert(6,3);
    p1.insert(5,2);
    cout<<"Displaying list 1"<<endl;
    p1.display();

    cout<<"Enter in list 2:"<<endl;
    p2.insert(9,8);
    p2.insert(8,7);
    p2.insert(6,4);
    p2.insert(2,3);
    p2.insert(4,5);
    cout<<"Displaying list 2"<<endl;
    p2.display();
    cout << "After adding " << endl;
    p3 = p1 + p2;
    p3.display();

    return 0;
}