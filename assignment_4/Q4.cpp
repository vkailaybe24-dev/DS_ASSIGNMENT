#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void findFirstNonRepeating() {
    const int MAX_CHARS = 256;
    vector<int> charCount(MAX_CHARS, 0);
    queue<char> q;
    string str;
    
    cout << "Enter a string (e.g., aabccbd): ";
    cin >> str;

    cout << "First non-repeating character after each step:\n";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        charCount[ch]++;
        
        if (charCount[ch] == 1) {
            q.push(ch);
        }

        while (!q.empty() && charCount[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << "Read '" << ch << "': First non-repeating is '" << q.front() << "'\n";
        } else {
            cout << "Read '" << ch << "': No non-repeating character found.\n";
        }
    }
}

int main() {
    findFirstNonRepeating();
    return 0;
}
