#include<bits/stdc++.h>
using namespace std;


int partition(int* arr, int s, int e){
    int pi = arr[s];
    int count = 0;

    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pi) count++;
    }

    int piIdx = s + count;
    swap(arr[piIdx], arr[s]);

    int i = s, j = e;
    while(i < piIdx && j > piIdx){
        while(arr[i] < pi) i++;
        while(arr[j] > pi) j++;

        if(i < piIdx && j > piIdx){
            swap(arr[i++], arr[j--]);
        }
    }

    return piIdx;
}

void quicksort(int* arr, int s, int e){
    if(s >= e){
        return;
    }
    int pi =  partition(arr, s, e);
    quicksort(arr, 0, pi-1);
    quicksort(arr, pi+1, e);
}
int main(){
    int arr[6] = {23,1,45,6,15,10};

    int n = 6;

    quicksort(arr, 0, n);

    for(auto i: arr) cout << i << endl;
    return 0;
}