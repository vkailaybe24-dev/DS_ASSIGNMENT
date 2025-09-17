#include <iostream>
#include <queue>

using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Input queue must have an even number of elements.\n";
        return;
    }

    queue<int> firstHalf;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    cout << "Original queue: 11 12 13 14 15 16\n";
    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
