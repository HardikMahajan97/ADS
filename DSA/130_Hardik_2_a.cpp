#include<iostream>
#include<string>
using namespace std;

struct Employee {
    int empID;
    string empName;
    double empSalary;
};

void swap(Employee* a, Employee* b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Employee arr[], int first, int last) {
    int pivot = arr[last].empID;
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (arr[j].empID < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(Employee arr[], int first, int last) {
    if (first >= last) return;

    int pi = partition(arr, first, last);
    quickSort(arr, first, pi - 1);
    quickSort(arr, pi + 1, last);
}

void display(Employee arr[], int size) {
    cout << "EMP-ID\tEMP-Name\tEMP-Salary" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i].empID << "\t" << arr[i].empName << "\t" << arr[i].empSalary << endl;
    }
    cout << endl;
}

int main() {
    Employee employees[20] = {
        {110, "Amit", 70000},
        {103, "Rahul", 55000},
        {120, "Sneha", 60000},
        {109, "Vijay", 75000},
        {102, "Priya", 80000},
        {107, "Kiran", 65000},
        {111, "Rohan", 62000},
        {105, "Meena", 72000},
        {115, "Ajay", 58000},
        {101, "Pooja", 69000},
        {114, "Ravi", 76000},
        {118, "Laxmi", 82000},
        {104, "Neha", 63000},
        {119, "Manoj", 54000},
        {106, "Shweta", 66000},
        {108, "Rajesh", 74000},
        {116, "Anjali", 68000},
        {113, "Vivek", 61000},
        {112, "Ritu", 71000},
        {117, "Tanvi", 64000}
    };

    int n = sizeof(employees) / sizeof(employees[0]);

    cout << "Original Employee List:" << endl;
    display(employees, n);

    // Sort employees based on EMP-ID using QuickSort
    quickSort(employees, 0, n - 1);

    cout << "Employee List Sorted by EMP-ID:" << endl;
    display(employees, n);

    return 0;
}
