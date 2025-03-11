#include<iostream>
using namespace std;

int partition(int arr[], int first, int last){
    int pivot = arr[last];
    int i = first - 1;
    int j = first;
    for(; j < last; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last){
    if(first >= last) return;

    int pi = partition(arr, first, last);
    quickSort(arr, first, pi -1);
    quickSort(arr, pi + 1, last);

}


void display(int* arr){
    cout<<endl;
    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {10, 12, 14, 15, 11, 13, 17, 19, 21, 20}; 
    cout<<"Original Array: ";
    display(arr);
    quickSort(arr, 0, 10);
    cout<<"Displaying sorted array : ";
    display(arr);
    return 0;
}