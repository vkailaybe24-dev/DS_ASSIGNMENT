#include<iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int min_idx = i;
        int max_idx = i;
        for(int j=i; j<n-i; j++){
            if(arr[j] < arr[min_idx]) min_idx = j;
            if(arr[j] > arr[max_idx]) max_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        if(max_idx == i) max_idx = min_idx;
        swap(arr[n-1-i], arr[max_idx]);
    }
}
int main(){
    int arr[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    improvedSelectionSort(arr, n);
    cout<<"Sorted array: \n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
