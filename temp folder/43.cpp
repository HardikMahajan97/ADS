#include <iostream>
using namespace std;
int main() {
    int arr[] = {8,1,2,2,3};
    int count ;
    int countArr[5];
    for(int i = 0; i < 5; i++){
        count  = 0;
        for(int j = 1; j < 5; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
        countArr[i] = count;
    }
    cout<<"Count Array:"<<endl;
    for(int i = 0; i < 5; i++){
        cout<<countArr[i]<<endl;
    }

    return 0;
}
