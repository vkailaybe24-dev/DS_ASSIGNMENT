#include <iostream>
#include <vector>

using namespace std;

int main() {
    int my_ints[] = {1, 2, 4, 5, 6};
    vector<int> arr(my_ints, my_ints + 5);

    // The full list should have n+1 numbers (from 1 to 6)
    int n = arr.size();
    int expected_sum = (n + 1) * (n + 2) / 2;

    // Calculate the actual sum of elements in the array
    int actual_sum = 0;
    for (int i = 0; i < n; ++i) {
        actual_sum += arr[i];
    }

    int missing_number = expected_sum - actual_sum;
    cout << "Missing number is " << missing_number << endl;

    return 0;
}
