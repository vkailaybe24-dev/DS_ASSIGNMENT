#include <iostream>
#define MAX_SIZE 5

using namespace std;

class CircularQueue {
private:
    int items[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE));
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
        rear = (rear + 1) % MAX_SIZE;
        items[rear] = value;
        cout << value << " enqueued to queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int item = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
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
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << items[i] << " ";
        }
        cout << items[i] << "\n";
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(4);
    q.display();
    return 0;
}
