#include<iostream>
using namespace std;

int quick(int *arr, int start, int low){
    int pivot = arr[low];
    int i = start - 1;
    for(int j = start; j < low; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[i+1];
    arr[i+1] = temp;
    return i + 1;
}

void quickSort(int *arr, int start, int end){
    if(start >= end){
        return;
    }
    int pi = quick(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);

}

void display(int *arr, int size){
    cout<<"Displaying the sorted array : "<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[] = {3,6,8,10,1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, size-1);
    display(arr, size);
    return 0;
}