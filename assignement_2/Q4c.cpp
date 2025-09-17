#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "This is a test string.";
    string result = "";

    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }

    cout << "String after removing vowels: " << result << endl;
    return 0;
}
