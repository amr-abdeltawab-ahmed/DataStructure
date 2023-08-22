#include <iostream>
using namespace std;

// Define the Doubly Linked List node
template <typename T>
struct DListNode {
    T data;
    DListNode<T> *prev;
    DListNode<T> *next;
    DListNode(T val): data(val), prev(nullptr), next(nullptr) {}
};

// Define the Doubly Linked List class
template <typename T>
class DoublyLinkedList {
private:
    DListNode<T> *head;
    DListNode<T> *tail;
    int size;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), size(0) {}

    // Insert at the head of the list
    void insertAtHead(T val) {
        DListNode<T> *newNode = new DListNode<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at the tail of the list
    void insertAtTail(T val) {
        DListNode<T> *newNode = new DListNode<T>(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Insert at a specified index
    void insertAt(T val, int index) {
        if (index < 0 || index > size) {
            cout << "Error: Index out of range." << endl;
            return;
        }
        if (index == 0) {
            insertAtHead(val);
            return;
        }
        if (index == size) {
            insertAtTail(val);
            return;
        }
        DListNode<T> *newNode = new DListNode<T>(val);
        DListNode<T> *curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        size++;
    }

    // Insert after a specified node
    void insertAfter(DListNode<T> *prev_node, T val) {
        if (prev_node == nullptr) {
            cout << "Error: Previous node cannot be null." << endl;
            return;
        }
        if (prev_node == tail) {
            insertAtTail(val);
            return;
        }
        DListNode<T> *newNode = new DListNode<T>(val);
        newNode->next = prev_node->next;
        newNode->prev = prev_node;
        prev_node->next->prev = newNode;
        prev_node->next = newNode;
        size++;
    }

    // Remove the head node
    void removeAtHead() {
        if (head == nullptr) {
            cout << "Error: List is empty." << endl;
            return;
        }
        DListNode<T> *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Returns true if the list is empty, false otherwise
    bool isEmpty() {
        return head == nullptr;
    }

    // Returns the size of the list
    int doubleLinkedListSize() {
        return size;
    }

    // Remove the last element of the list
    void removeAtTail()
    {
        if (isEmpty())
        {
            cout << "The list is empty. Cannot remove an element." << endl;
        }
        else if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else
        {
            T *temp = tail;
            tail = tail->back;
            tail->next = nullptr;
            delete temp;
            size--;
        }
    }

    // Remove an element at a specified index
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds. Cannot remove an element." << endl;
        }
        else if (index == 0)
        {
            removeAtHead();
        }
        else if (index == size - 1)
        {
            removeAtTail();
        }
        else
        {
            T *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            current->back->next = current->next;
            current->next->back = current->back;

            delete current;
            size--;
        }
    }

    // Retrieve an element at a specified index
    T retrieveAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds. Cannot retrieve an element." << endl;
            return;
        }
        else if (index == 0)
        {
            return head->info;
        }
        else if (index == size - 1)
        {
            return tail->info;
        }
        else
        {
            T *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            return current->info;
        }
    }

    // Replace an element at a specified index with a new element
    void replaceAt(T newElement, int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds. Cannot replace an element." << endl;
        }
        else if (index == 0)
        {
            head->info = newElement;
        }
        else if (index == size - 1)
        {
            tail->info = newElement;
        }
        else
        {
            T *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            current->info = newElement;
        }
    }

    // Check if an element exists in the list
    bool isExist(T element)
    {
        T *current = head;
        while (current != nullptr)
        {
            if (current->info == element)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        DListNode<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx == secondItemIdx) {
            return;
        }

        if (firstItemIdx > secondItemIdx) {
            swap(secondItemIdx, firstItemIdx);
        }

        DListNode<T>* first = head;
        for (int i = 0; i < firstItemIdx; i++) {
            first = first->next;
        }

        DListNode<T>* second = head;
        for (int i = 0; i < secondItemIdx; i++) {
            second = second->next;
        }

        if (first->next == second) {
            first->next = second->next;
            second->prev = first->prev;
            first->prev = second;
            second->next = first;
            if (first->next) {
                first->next->prev = first;
            }
            if (second->prev) {
                second->prev->next = second;
            }
        } else if (second->next == first) {
            second->next = first->next;
            first->prev = second->prev;
            second->prev = first;
            first->next = second;
            if (second->next) {
                second->next->prev = second;
            }
            if (first->prev) {
                first->prev->next = first;
            }
        } else {
            DListNode<T>* temp = first->next;
            first->next = second->next;
            second->next = temp;

            if (first->next) {
                first->next->prev = first;
            }
            if (second->next) {
                second->next->prev = second;
            }

            temp = first->prev;
            first->prev = second->prev;
            second->prev = temp;

            if (first->prev) {
                first->prev->next = first;
            }
            if (second->prev) {
                second->prev->next = second;
            }

            if (firstItemIdx == 0) {
                head = second;
            } else if (secondItemIdx == 0) {
                head = first;
            }

            if (firstItemIdx == size - 1) {
                tail = second;
            } else if (secondItemIdx == size - 1) {
                tail = first;
            }
        }
    }

    void reverse() {
        DListNode<T>* current = head;
        DListNode<T>* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void clear() {
        DListNode<T>* current = head;
        DListNode<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void forwardTraversal() {
        DListNode<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void backwardTraversal() {
        DListNode<T>* current = tail;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }



};