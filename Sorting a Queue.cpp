#include <iostream>
#include "Queue.cpp"
using namespace std;

template <class T>
void sortQueue(Queue<T>& q) {
    int n = q.queueSize();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Find the minimum element in the remaining unsorted part of the queue
        for (int j = i + 1; j < n; j++) {
            if (q.first() < q.dequeue()) {
                min_idx = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted part
        int min_val = q.dequeue();
        for (int j = 0; j < min_idx; j++) {
            q.enqueue(q.dequeue());
        }
        q.enqueue(min_val);
    }
}

int main() {
    Queue<int> q;

    // Example queue 1
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);

    cout << "Original queue: ";
    q.print();

    sortQueue(q);

    cout << "Sorted queue: ";
    q.print();

    // Example queue 2
    q.clear();
    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);

    cout << "Original queue: ";
    q.print();

    sortQueue(q);

    cout << "Sorted queue: ";
    q.print();

    return 0;
}
