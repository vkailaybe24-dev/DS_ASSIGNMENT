#include <iostream>
#include <vector>

using namespace std;

int main() {
    int my_ints[] = {2, 3, 4, 10, 40};
    vector<int> arr(my_ints, my_ints + 5);

    int key_to_find = 10;
    int left = 0;
    int right = arr.size() - 1;
    int result_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key_to_find) {
            result_index = mid;
            break; // Found the key, exit loop
        }
        if (arr[mid] < key_to_find) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    if (result_index == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result_index << endl;
    }
    return 0;
}
