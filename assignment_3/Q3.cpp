#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

struct CharStack {
    char arr[MAX_SIZE];
    int top;
};

void init(CharStack& s) { s.top = -1; }
bool isEmpty(CharStack& s) { return s.top == -1; }
void push(CharStack& s, char val) { s.arr[++s.top] = val; }
char pop(CharStack& s) { return s.arr[s.top--]; }
char peek(CharStack& s) { return s.arr[s.top]; }


bool areParenthesesBalanced(string expr) {
    CharStack s;
    init(s);

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(s, ch);
            continue;
        }

        if (isEmpty(s)) {
            return false;
        }
        
        char top_char = pop(s);
        if (ch == ')' && top_char != '(') return false;
        if (ch == ']' && top_char != '[') return false;
        if (ch == '}' && top_char != '{') return false;
    }
    return isEmpty(s);
}

int main() {
    string expr = "{[a+b]*(c-d)}";

    if (areParenthesesBalanced(expr)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }
    return 0;
}
