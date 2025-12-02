#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i, bool ascending){
    int target = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(ascending){
        if(l < n && arr[l] > arr[target]) target = l;
        if(r < n && arr[r] > arr[target]) target = r;
    } else {
        if(l < n && arr[l] < arr[target]) target = l;
        if(r < n && arr[r] < arr[target]) target = r;
    }
    if(target != i){
        swap(arr[i], arr[target]);
        heapify(arr, n, target, ascending);
    }
}
void heapSort(int arr[], int n, bool ascending){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; ++i) cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Original: "; printArray(arr1, n1);
    heapSort(arr1, n1, true);
    cout<<"Sorted (Inc): "; printArray(arr1, n1);
    int arr2[] = {12, 11, 13, 5, 6, 7};
    heapSort(arr2, n1, false);
    cout<<"Sorted (Dec): "; printArray(arr2, n1);
    return 0;
}
