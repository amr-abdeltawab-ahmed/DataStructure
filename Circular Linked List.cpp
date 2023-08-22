#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T element) {
        data = element;
        next = nullptr;
    }
};

template <typename T>
class CircularLinkedList {
private:
    Node<T> *head;
    int size;
public:
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }

    void insertAtHead(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node<T> *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node<T> *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtEnd(element);
        } else {
            Node<T> *newNode = new Node<T>(element);
            Node<T> *prev = nullptr;
            Node<T> *curr = head;
            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = newNode;
            newNode->next = curr;
            size++;
        }
    }

    void removeAtHead() {
        if (head == nullptr) {
            return;
        }
        Node<T> *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        Node<T> *temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            head = head->next;
        }
        tail->next = head;
        delete temp;
        size--;
    }

    void removeAtEnd() {
        if (head == nullptr) {
            return;
        }
        Node<T> *tail = head;
        Node<T> *prev = nullptr;
        while (tail->next != head) {
            prev = tail;
            tail = tail->next;
        }
        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = head;
        }
        delete tail;
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Error: Index out of range.\n";
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            size = 0;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }

        if (current == head) {
            head = current->next;
        }

        previous->next = current->next;
        delete current;
        size--;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range.");
        }

        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }

        return currentNode->data;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range.");
        }

        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }

        currentNode->data = newElement;
    }

    bool isExist(T element) {
        Node<T>* currentNode = head;
        for (int i = 0; i < size; i++) {
            if (currentNode->data == element) {
                return true;
            }
            currentNode = currentNode->next;
        }

        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range.");
        }

        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }

        return currentNode->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size ||
            secondItemIdx < 0 || secondItemIdx >= size ||
            firstItemIdx == secondItemIdx) {
            return;
        }

        Node<T>* firstNode = head;
        for (int i = 0; i < firstItemIdx; i++) {
            firstNode = firstNode->next;
        }

        Node<T>* secondNode = head;
        for (int i = 0; i < secondItemIdx; i++) {
            secondNode = secondNode->next;
        }

        // Swap the next pointers of the two nodes
        Node<T>* temp = firstNode->next;
        firstNode->next = secondNode->next;
        secondNode->next = temp;

        // Swap the previous pointers of the two nodes
        temp = firstNode->prev;
        firstNode->prev = secondNode->prev;
        secondNode->prev = temp;

        // Update the adjacent nodes' next and previous pointers
        firstNode->next->prev = firstNode;
        secondNode->next->prev = secondNode;
        firstNode->prev->next = firstNode;
        secondNode->prev->next = secondNode;
    }

    bool isEmpty() {
        return size == 0;
    }

    int circularLinkedListSize() {
        return size;
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    void print() const {
        if (head == nullptr) {
            std::cout << "The list is empty.\n";
        } else {
            Node<T>* current = head;
            do {
                std::cout << current->data << " ";
                current = current->next;
            } while (current != head);
            std::cout << "\n";
        }
    }


};