#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data): data(data), next(nullptr) {}
    };
    Node* topNode;
    int size;

public:
    Stack(): topNode(nullptr), size(0) {}

    void push(T element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    T pop() {
        if (isEmpty()) {
            throw "Stack is empty";
        }
        T element = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
        return element;
    }

    T top() {
        if (isEmpty()) {
            throw "Stack is empty";
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int stackSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void print() {
        Node* currNode = topNode;
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    ~Stack() {
        clear();
    }

};
