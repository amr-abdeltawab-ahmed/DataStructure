#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T element) {
        data = element;
        next = NULL;
    }
};

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void insertAtHead(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void insertAtTail(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > length) {
            cout << "Index out of range" << endl;
            return;
        }
        if (index == 0) {
            insertAtHead(element);
            return;
        }
        if (index == length) {
            insertAtTail(element);
            return;
        }
        Node<T> *newNode = new Node<T>(element);
        Node<T> *prev = head;
        for (int i = 0; i < index-1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
    }

    void removeAtHead() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removeAtTail() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            length--;
            return;
        }
        Node<T> *prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        prev->next = NULL;
        tail = prev;
        length--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == length-1) {
            removeAtTail();
            return;
        }
        Node<T> *prev = head;
        for (int i = 0; i < index-1; i++) {
            prev = prev->next;
        }
        Node<T> *temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return T();
        }
        Node<T> *current = head;
        for (int i = 0 ; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = newElement;
    }

    bool isExist(T element) {
        Node<T> *current = head;
        while (current != NULL) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return false;
        }
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= length || secondItemIdx < 0 || secondItemIdx >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node<T> *prev1 = NULL;
        Node<T> *current1 = head;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = current1;
            current1 = current1->next;
        }
        Node<T> *prev2 = NULL;
        Node<T> *current2 = head;
        for (int i = 0; i < secondItemIdx; i++) {
            prev2 = current2;
            current2 = current2->next;
        }
        if (prev1 != NULL) {
            prev1->next = current2;
        }
        else {
            head = current2;
        }
        if (prev2 != NULL) {
            prev2->next = current1;
        }
        else {
            head = current1;
        }
        Node<T> *temp = current1->next;
        current1->next = current2->next;
        current2->next = temp;
        if (current1 == tail) {
            tail = current2;
        }
        else if (current2 == tail) {
            tail = current1;
        }
    }

    bool isEmpty() {
        return head == NULL;
    }

    Node<T> * getHead() {
        return head;
    }

    int indexOf(Node<T>* head, int key) {
        int index = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }


    int linkedListSize() {
        return length;
    }

    void clear() {
        Node<T> *current = head;
        while (current != NULL) {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void print() {
        Node<T> *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
