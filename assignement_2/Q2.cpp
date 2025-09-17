#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

int main() {
    int my_ints[] = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr(my_ints, my_ints + 7);
    int n = arr.size();

    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
