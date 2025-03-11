#include <bits/stdc++.h>
using namespace std;

struct node{
    int prio;
    string job;
    node* next;
};

class jobSchedulingSystem{
    node* front;
    node* rear;

public:
    jobSchedulingSystem(){
        front = NULL;
        rear = NULL;
    }

    int isFrontEmpty(){
        return front == NULL;
    }

    int isRearEmpty(){
        return rear == NULL;
    }

    void addJob(string job, int prio){
        node* new_node = new node();
        new_node->job = job;
        new_node->prio = prio;

        // Base case : If the queue is empty.
        if(isFrontEmpty() && isRearEmpty()){
            front = rear = new_node;
            return;
        }

        // Check if the new node's priority is greater than the first priority.
        if (front->prio < prio){
            new_node->next = front;
            front = new_node;

        }else{
            // Insert the new node anywhere in the queue as per the priority.
            node* temp = front;
            while (temp->next != NULL && temp->next->prio > prio){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;

            if (new_node->next == nullptr) {
                rear = new_node;
            }
        }
    }

    void removeJob(){

        if (isFrontEmpty() && isRearEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }

        node* temp = front;
        cout << "The job with the highest priority is: " << temp->job << ", Priority: " << temp->prio << endl;
        front = front->next;
        if (front == NULL) {
            rear = NULL;  // Queue is now empty
        }
        delete temp;
    }

    void searchJob(string job){
        node* temp = front;
        while (temp != NULL){
            if (temp->job == job){
                cout << "The job has the priority: " << temp->prio << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No such job exists in the system!" << endl;
    }

    void display(){
        if (isFrontEmpty()){
            cout << "No jobs in the queue!" << endl;
            return;
        }
        
        node* temp = front;
        while (temp != NULL){
            cout << "Job Name: " << temp->job << ", Priority: " << temp->prio << endl;
            temp = temp->next;
        }
    }
};

int main(){
    jobSchedulingSystem j;
    int choice;
    string job;
    int prio;

    //Menu
    while(true){
        cout << "--- Job Scheduling System Menu ---" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Remove Job" << endl;
        cout << "3. Display All Jobs" << endl;
        cout << "4. Search for a Job" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter job name: ";
                cin >> job;
                cout << "Enter job priority: ";
                cin >> prio;
                j.addJob(job, prio);
                break;
            case 2:
                j.removeJob();
                break;
            case 3:
                j.display();
                break;
            case 4:
                cout << "Enter job name to search: ";
                cin >> job;
                j.searchJob(job);
                break;
            case 5:
                cout << "Quitting Job Scheduling System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 

    return 0;
}
