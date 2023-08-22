#include <iostream>

using namespace std;

template <class T>
class QueueNode {
public:
    T data;
    QueueNode<T>* next;

    QueueNode(T value) {
        data = value;
        next = nullptr;
    }
};

template <class T>
class Queue {
private:
    QueueNode<T>* head;
    QueueNode<T>* tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Queue() {
        clear();
    }

    void enqueue(T element) {
        QueueNode<T>* newNode = new QueueNode<T>(element);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        QueueNode<T>* nodeToRemove = head;
        T data = nodeToRemove->data;
        head = head->next;
        delete nodeToRemove;
        size--;
        return data;
    }

    T first() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    bool isEmpty() {
        return (size == 0);
    }

    int queueSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void print() {
        QueueNode<T>* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

};
