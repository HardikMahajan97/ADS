#include <iostream>
using namespace std;

bool checkForRepeatedValues(int *arr, int size){

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    if(checkForRepeatedValues(arr, n)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
    
}