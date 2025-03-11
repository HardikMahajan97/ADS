#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    int rollNo;
    string name;
    float sgpa;
};

void shellSort(Student arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            Student temp = arr[i];
            int j = i;
            while ( j >= gap && arr[j - gap].name > temp.name)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void display(Student arr[], int n) 
{
    cout << "Roll No\tName\t\tSGPA" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i].rollNo << "\t" << arr[i].name << "\t\t" << arr[i].sgpa << endl;
    }
}

int main() {
    Student students[] = {
        {110, "Jack", 8.3},
        {101, "Alice", 8.5},
        {107, "Grace", 8.8},
        {102, "Bob", 7.9},
        {112, "Liam", 7.5},
        {105, "Eve", 7.7},
        {103, "Charlie", 8.0},
        {104, "David", 9.1},
        {115, "Oscar", 7.6},
        {106, "Frank", 8.2},
        {108, "Heidi", 9.0},
        {109, "Ivy", 7.8},
        {111, "Kevin", 8.6},
        {114, "Nina", 8.9},
        {113, "Mallory", 8.1},
    };
    int n = sizeof(students) / sizeof(students[0]);

    cout << "Student Database Before Sorting:" << endl;
    display(students, n);

    shellSort(students, n);

    cout << "\nStudent Database After Sorting by Name:" << endl;
    display(students, n);

    return 0;
}
