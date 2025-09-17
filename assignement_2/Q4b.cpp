#include <iostream>
#include <string>
#include <utility> 
using namespace std;

int main() {
    string str = "program";
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(str[i], str[n - i - 1]);
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
