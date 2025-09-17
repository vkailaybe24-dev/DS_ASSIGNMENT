#include <iostream>
#include <vector>

using namespace std;

struct Term {
    int row, col, value;
};


void printSparse(const vector<Term>& matrix, int rows, int cols) {
    cout << "Row\tCol\tValue" << endl;
    cout << rows << "\t" << cols << "\t" << matrix.size() << endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << matrix[i].row << "\t" << matrix[i].col << "\t" << matrix[i].value << endl;
    }
}

int main() {
    int rows = 4, cols = 4;
    vector<Term> a;
    a.push_back((Term){0, 1, 1});
    a.push_back((Term){1, 2, 2});
    a.push_back((Term){2, 0, 3});
    a.push_back((Term){3, 1, 4});

    cout << "Original Matrix A:" << endl;
    printSparse(a, rows, cols);

    
    vector<Term> b(a.size());
    int currentB = 0;
    for (int c = 0; c < cols; ++c) { 
        for (size_t i = 0; i < a.size(); ++i) { 
            if (a[i].col == c) {
                b[currentB].row = a[i].col;
                b[currentB].col = a[i].row;
                b[currentB].value = a[i].value;
                currentB++;
            }
        }
    }

    cout << "\nTranspose of Matrix A:" << endl;
    printSparse(b, cols, rows); 

    return 0;
}
