#include<iostream>
using namespace std;

void countSort(int arr[], int pos, int size){
    int freq[10] = {0};
    //Frequency Array
    for(int i = 0; i < size; i++){
        freq[(arr[i]/pos) % 10]++;   // Stores the frequency of the element being index as the value.
    }

    //Cummulative frequency array
    for(int i = 1; i < size; i++){
        freq[i]+= freq[i-1];
    }

    //Sorted Array
    int sortedArray[size] ;
    for(int i = size - 1; i >= 0; i--){
        sortedArray[--freq[(arr[i]/pos) % 10]] = arr[i];
    }

    //copying back to the original array.
    for(int i = 0; i < size; i++){
        arr[i] = sortedArray[i];
    }
}

void radixSort(int arr[], int size){

    int maximum = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > maximum)
            maximum = arr[i];
    }

    for(int pos = 1; maximum / pos > 0; pos*=10){
        countSort(arr, pos, size);       
    }
    
}

void display(int arr[], int size){

    for(int i = 0; i < size; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[] = {122,231,123,432,433,531};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"\nOriginal Array:"<<endl;
    display(arr, size);

    radixSort(arr, size);

    cout<<"Sorted Array:"<<endl;
    display(arr, size);
    return 0;
}