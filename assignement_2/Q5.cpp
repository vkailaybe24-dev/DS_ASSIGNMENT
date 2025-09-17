#include <iostream>
#include <vector>

using namespace std;

int main() {
    int dim = 4; 
    vector<int> storage;

    cout << "Setting matrix values:" << endl;
    for (int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= i; ++j) {
            int value = i + j; 
            storage.push_back(value);
            cout << value << " ";
        }
        cout << endl;
    }

    
    cout << "\nDisplaying full 4x4 matrix:" << endl;
    for (int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim; ++j) {
            if (i >= j) {
                
                int index = (i * (i - 1) / 2) + (j - 1);
                cout << storage[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
