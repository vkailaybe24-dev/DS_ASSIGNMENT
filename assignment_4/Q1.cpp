#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Queue {
private:
    int items[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        items[rear] = value;
        cout << value << " enqueued to queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int item = items[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return items[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Check if Full\n";
        cout << "5. Check if Empty\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1) {
                    cout << value << " dequeued from queue.\n";
                }
                break;
            case 3:
                 value = q.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << "\n";
                }
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 6:
                q.display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
