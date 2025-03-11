#include <iostream>
#include <string>
using namespace std;

class Employee {
    int empID;
    string name;
    int contact;
    bool isOccupied;
    bool isDeleted; 

public:
    Employee() {
        empID = -1;
        contact = 0;
        isOccupied = false;
        isDeleted = false;
    }

    void setEmployee(int id, string n, int cont) {
        empID = id;
        name = n;
        contact = cont;
        isOccupied = true;
        isDeleted = false;
    }

    void deleteEmployee() {
        isOccupied = false;
        isDeleted = true;
    }

    int getID() {
        return empID;
    }

    void printEmployee() {
        if (isOccupied) {
            cout << "Employee ID: " << empID << endl;
            cout << "Name: " << name << endl;
            cout << "Contact: " << contact << endl;
        } else if (isDeleted) {
            cout << "Deleted slot" << endl;
        } else {
            cout << "Empty slot" << endl;
        }
    }

    bool isSlotOccupied() {
        return isOccupied;
    }

    bool isSlotDeleted() {
        return isDeleted;
    }
};

class HashTable {
    int tableSize; // Size of the hash table
    Employee* ht;

public:
    HashTable(int size) {
        tableSize = size;
        ht = new Employee[tableSize];
    }

    int hash(int value) {
        return (value % tableSize);
    }

    // Inserts an employee into the hash table using linear probing
    void insertIntoHT(int empID, string n, int contact) {
        int ToBeInsertedAt = hash(empID);

        // If the slot is empty or previously deleted, insert directly
        if (!ht[ToBeInsertedAt].isSlotOccupied() || ht[ToBeInsertedAt].isSlotDeleted()) {
            ht[ToBeInsertedAt].setEmployee(empID, n, contact);
        } else {
        // Use linear probing to find the next slot in sequential manner.
            for (int i = 0; i < tableSize; i++) {
                // Increments the index by 1.
                ToBeInsertedAt = (ToBeInsertedAt + 1) % tableSize;
                if (!ht[ToBeInsertedAt].isSlotOccupied() || ht[ToBeInsertedAt].isSlotDeleted()) {
                    ht[ToBeInsertedAt].setEmployee(empID, n, contact);
                    return;
                }
            }
            cout << "Hashtable is full" << endl;
        }
    }

    void displayHT() {
        for (int i = 0; i < tableSize; i++) {
            ht[i].printEmployee();
        }
    }

    void searchHT(int empID) {
        int ToBeInsertedAt = hash(empID);

        // Check if the employee is at the hashed index
        if (ht[ToBeInsertedAt].getID() == empID && !ht[ToBeInsertedAt].isSlotDeleted()) {
            ht[ToBeInsertedAt].printEmployee();
        } else {
            // If not found, use linear probing to search further which searches for an empty slot in a
            //sequential manner.
            for (int i = 0; i < tableSize; i++) {
                ToBeInsertedAt = (ToBeInsertedAt + 1) % tableSize;
                if (ht[ToBeInsertedAt].getID() == empID && !ht[ToBeInsertedAt].isSlotDeleted()) {
                    ht[ToBeInsertedAt].printEmployee();
                    return;
                }
            }
            cout << "Details not found" << endl;
        }
    }

    void deleteFromHT(int empID) {
        int ToBeDeletedAt = hash(empID);

        // Check if the employee is at the hashed index
        if (ht[ToBeDeletedAt].getID() == empID && !ht[ToBeDeletedAt].isSlotDeleted()) {
            ht[ToBeDeletedAt].deleteEmployee();
            cout << "Employee with ID " << empID << " deleted." << endl;
        } else {
            // If not found, use linear probing to search further
            for (int i = 0; i < tableSize; i++) {
                ToBeDeletedAt = (ToBeDeletedAt + 1) % tableSize;
                if (ht[ToBeDeletedAt].getID() == empID && !ht[ToBeDeletedAt].isSlotDeleted()) {
                    ht[ToBeDeletedAt].deleteEmployee();
                    cout << "Employee with ID " << empID << " deleted." << endl;
                    return;
                }
            }
            cout << "Employee ID " << empID << " not found." << endl;
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table of size 10
    int choice, empID, contact;
    string name;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Insert Employee
            cout << "Enter Employee ID: ";
            cin >> empID;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Contact: ";
            cin >> contact;
            ht.insertIntoHT(empID, name, contact);
            cout << "Employee inserted successfully!" << endl;
            break;

        case 2: // Display all Employees
            ht.displayHT();
            break;

        case 3: // Search Employee
            cout << "Enter Employee ID to search: ";
            cin >> empID;
            ht.searchHT(empID);
            break;

        case 4: // Delete Employee
            cout << "Enter Employee ID to delete: ";
            cin >> empID;
            ht.deleteFromHT(empID);
            break;

        case 5: // Exit
            return 0;

        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}