#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

struct IntStack {
    int arr[MAX_SIZE];
    int top;
};

void init(IntStack& s) { s.top = -1; }
bool isEmpty(IntStack& s) { return s.top == -1; }
void push(IntStack& s, int val) { s.arr[++s.top] = val; }
int pop(IntStack& s) { return s.arr[s.top--]; }
int peek(IntStack& s) { return s.arr[s.top]; }

int evaluatePostfix(string expr) {
    IntStack s;
    init(s);

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c >= '0' && c <= '9') {
            push(s, c - '0');
        } else {
            int op2 = pop(s);
            int op1 = pop(s);

            switch (c) {
                case '+': push(s, op1 + op2); break;
                case '-': push(s, op1 - op2); break;
                case '*': push(s, op1 * op2); break;
                case '/': push(s, op1 / op2); break;
            }
        }
    }
    return pop(s);
}

int main() {
    string postfix_expression = "231*+9-";
    int result = evaluatePostfix(postfix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;
    cout << "Result: " << result << endl;
    return 0;
}
