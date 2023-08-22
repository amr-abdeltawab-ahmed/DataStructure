#include <iostream>
#include "Queue.cpp"

template <class T>
class Stack {
private:
    Queue<T> q1;
    Queue<T> q2;

public:
    void push(T element) {
        if (q1.isEmpty()) {
            q2.enqueue(element);
        }
        else {
            q1.enqueue(element);
        }
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        T topElement;
        if (q1.isEmpty()) {
            while (q2.queueSize() > 1) {
                q1.enqueue(q2.dequeue());
            }
            topElement = q2.dequeue();
        }
        else {
            while (q1.queueSize() > 1) {
                q2.enqueue(q1.dequeue());
            }
            topElement = q1.dequeue();
        }
        return topElement;
    }

    T top() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        T topElement;
        if (q1.isEmpty()) {
            while (q2.queueSize() > 1) {
                q1.enqueue(q2.dequeue());
            }
            topElement = q2.first();
            q1.enqueue(q2.dequeue());
        }
        else {
            while (q1.queueSize() > 1) {
                q2.enqueue(q1.dequeue());
            }
            topElement = q1.first();
            q2.enqueue(q1.dequeue());
        }
        return topElement;
    }

    bool isEmpty() {
        return (q1.isEmpty() && q2.isEmpty());
    }

    int size() {
        return (q1.queueSize() + q2.queueSize());
    }

};
