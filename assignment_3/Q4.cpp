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


int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    CharStack st;
    init(st);
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (c == '(') {
            push(st, '(');
        } else if (c == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                result += pop(st);
            }
            pop(st);
        } else {
            while (!isEmpty(st) && precedence(c) <= precedence(peek(st))) {
                result += pop(st);
            }
            push(st, c);
        }
    }

    while (!isEmpty(st)) {
        result += pop(st);
    }

    return result;
}

int main() {
    string infix_expression = "a+b*(c^d-e)";
    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Infix expression: " << infix_expression << endl;
    cout << "Postfix expression: " << postfix_expression << endl;
    return 0;
}
