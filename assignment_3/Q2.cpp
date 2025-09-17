#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

struct CharStack {
    char arr[MAX_SIZE];
    int top;
};

void init(CharStack& s) {
    s.top = -1;
}

bool isEmpty(CharStack& s) {
    return s.top == -1;
}

bool isFull(CharStack& s) {
    return s.top == MAX_SIZE - 1;
}

void push(CharStack& s, char value) {
    if (isFull(s)) {
        return;
    }
    s.arr[++s.top] = value;
}

char pop(CharStack& s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s.arr[s.top--];
}

int main() {
    string input = "DataStructure";
    CharStack s;
    init(s);

    for (int i = 0; i < input.length(); ++i) {
        push(s, input[i]);
    }

    string reversed_string = "";
    while (!isEmpty(s)) {
        reversed_string += pop(s);
    }

    cout << "Original string: " << input << endl;
    cout << "Reversed string: " << reversed_string << endl;

    return 0;
}
