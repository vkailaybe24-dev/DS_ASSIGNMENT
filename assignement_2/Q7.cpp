#include <iostream>
#include <vector>

using namespace std;

int main() {
    int my_ints[] = {8, 4, 2, 1};
    vector<int> arr(my_ints, my_ints + 4);

    int inv_count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }

    cout << "Number of inversions are " << inv_count << endl;
    return 0;
}
