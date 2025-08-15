#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += a[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << sum << "\n";
    }

    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += a[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << sum << "\n";
    }

    return 0;
}

