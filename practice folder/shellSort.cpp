#include<bits/stdc++.h>
using namespace std;

struct student{
    int r;
    float mr;
    string name;
};

void shellSort(student *arr, int n){
    for(int gap = n/2; gap > 0; gap/=2){
        for(int i = gap; i < n; i++){
            student temp = arr[i];
            int j = i;
            while( j>=0 && arr[j - gap].name > temp.name){
                arr[j] = arr[j - gap];
                j = j - gap;
            }

            arr[j] = temp;
        }
    }
}

int main(){
    struct student arr[3];
    cout << "Enter Name, roll number, marks :" << endl;
    for(int i = 0; i < 3; i++){
        cin >> arr[i].name >> arr[i].r >> arr[i].mr;
    }

    shellSort(arr, 3);
    for(int i = 0; i < 3; i++){
        cout << arr[i].name << endl << arr[i].r << endl << arr[i].mr << endl;
    }

    return 0;
}