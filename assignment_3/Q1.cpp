#include <iostream>

using namespace std;

#define STACK_SIZE 10

struct Stack {
    int arr[STACK_SIZE];
    int top;
};

void init(Stack& s) {
    s.top = -1;
}

bool isFull(Stack& s) {
    return s.top == STACK_SIZE - 1;
}

bool isEmpty(Stack& s) {
    return s.top == -1;
}

void push(Stack& s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push." << endl;
        return;
    }
    s.top++;
    s.arr[s.top] = value;
    cout << value << " was pushed to the stack." << endl;
}

int pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! Cannot pop." << endl;
        return -1;
    }
    int value = s.arr[s.top];
    s.top--;
    return value;
}

int peek(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return s.arr[s.top];
}

void display(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack my_stack;
    init(my_stack);
    int choice, value;

    while (true) {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(my_stack, value);
                break;
            case 2:
                value = pop(my_stack);
                if (!isEmpty(my_stack) || value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                value = peek(my_stack);
                if (!isEmpty(my_stack) || value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;
            case 4:
                display(my_stack);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}	
