#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while( j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {12,13,14,1,2,3,4,5,6,6,7,8,8,8};

    int n = 14;

    insertionSort(arr, n);
    cout << "Sorted order" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}