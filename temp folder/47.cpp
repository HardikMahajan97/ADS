#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int sum =  (n * ( n + 1)) / 2;
    int arrSum = 0;
    for(int i  = 0; i < n; i++){
        arrSum += arr[i];
    }
    if(arrSum == sum){
        cout<<"No missing element!"<<endl;
        return 0;
    }
    cout<<"Missing element is : "<<(sum - arrSum)<<endl;
    return 0;
}