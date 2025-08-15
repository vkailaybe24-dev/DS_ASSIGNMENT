#include <iostream>
using namespace std;

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int trans[3][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            trans[j][i] = a[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << trans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

