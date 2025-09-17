#include <iostream>
#include <vector>

using namespace std;

int main() {
    int my_ints[] = {1, 2, 3, 4, 6, 7, 8};
    vector<int> arr(my_ints, my_ints + 7);

    int left = 0, right = arr.size() - 1;
    int missing_number = arr.size() + 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1) {
            missing_number = mid + 1;
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }

    cout << "Missing number is " << missing_number << endl;
    return 0;
}
