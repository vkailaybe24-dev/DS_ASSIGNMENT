#include <iostream>
#include <queue>
#include <algorithm> // For std::swap

using namespace std;

// (a) Using Two Queues
class StackUsingTwoQueues {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed to stack.\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << q1.front() << " popped from stack.\n";
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            return -1;
        }
        return q1.front();
    }
};

// (b) Using One Queue
class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed to stack.\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << q.front() << " popped from stack.\n";
        q.pop();
    }

    int top() {
        if (q.empty()) {
            return -1;
        }
        return q.front();
    }
};

int main() {
    cout << "--- Stack using two queues ---\n";
    StackUsingTwoQueues s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.pop();
    s2.pop();
    
    cout << "\n--- Stack using one queue ---\n";
    StackUsingOneQueue s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    s1.pop();

    return 0;
}
