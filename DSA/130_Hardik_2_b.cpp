#include<iostream>
#include<string>
using namespace std;

struct Employee {
    int empID;
    string empName;
    double empSalary;
};

void Display(Employee A[], int n) {
    cout << "\n";
    cout << "EMP-ID\tEMP-Name\tEMP-Salary" << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i].empID << "\t" << A[i].empName << "\t" << A[i].empSalary << endl;
    }
    cout << endl;
}

void Merge(Employee A[], int start, int mid, int end, Employee temp[]) {
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (A[i].empName < A[j].empName) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= end) {
        temp[k++] = A[j++];
    }

    for (i = start, k = 0; i <= end; i++, k++) {
        A[i] = temp[k];
    }
}

void MergeSort(Employee A[], int start, int end, Employee temp[]) {
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    MergeSort(A, start, mid, temp);
    MergeSort(A, mid + 1, end, temp);

    Merge(A, start, mid, end, temp);
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
    Employee temp[20];

    cout << "Original Employee List:" << endl;
    Display(employees, n);

    MergeSort(employees, 0, n - 1, temp);

    cout << "Employee List Sorted Alphabetically by Name:" << endl;
    Display(employees, n);

    return 0;
}
