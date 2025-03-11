#include<iostream>
#include<math.h>

using namespace std;


void Merge(int A[], int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    int newA[ (e - s) + 1];
    int k = 0;
    while( i <= mid && j <= e){
        if(A[i] < A[j] ) {
            newA[k] = A[i];
            i++;
        }
        else {
            newA[k] = A[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        newA[k] = A[i];
        i++;
        k++;
    }
    while(j <= e){
        newA[k] = A[j];
        j++;
        k++;
    }
    for(int i = 0, j = s; i < k; i++, j++)
        A[j] = newA[i];
    return;
}

void MergeSort(int A[], int s, int e) {
// keep spliting the array into 2 halves
// till there is only 1 element in the array
//merge
    if(s >= e)
        return;

    int m = (s + e) / 2;
    MergeSort(A, s, m);
    MergeSort(A, m + 1, e);
    Merge(A, s, m, e);

    return;

}
void Display(int A[], int n){
    cout<<"\n";
    for(int i = 0; i < n; i++)
    cout<<A[i]<<"\t";
    cout<<endl;
    return;
}

int main() {

    int A[] = {734, 756, 778 ,812, 990, 1055, 688, 740, 823, 855, 966, 972};
    int n = sizeof(A)/sizeof(int);
    Display(A, n);

    MergeSort(A, 0, n - 1);
    Display(A, n);
    return 0;
}