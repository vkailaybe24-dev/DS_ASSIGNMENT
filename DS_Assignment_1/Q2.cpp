#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 10, 30, 40, 20, 50, 30};
    int n = 8;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
                j--;
            }
        }
    }

    cout << "After Removing Duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

