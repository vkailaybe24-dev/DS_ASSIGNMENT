#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int my_ints[] = {10, 20, 20, 10, 30, 40, 40, 50};
    vector<int> arr(my_ints, my_ints + 8);

    if (arr.empty()) {
        cout << "Total distinct elements are 0" << endl;
        return 0;
    }

    
    sort(arr.begin(), arr.end());

    
    int distinct_count = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
       
        if (arr[i] != arr[i - 1]) {
            distinct_count++;
        }
    }

    cout << "Total distinct elements are " << distinct_count << endl;
    return 0;
}
