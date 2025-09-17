#include <iostream>
#include <string>
#include <vector>
#include <utility> 

using namespace std;

int main() {
    const int N = 5;
    string arr[N] = {"Banana", "Apple", "Orange", "Grapes", "Cherry"};

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] > arr[j]) { 
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}
