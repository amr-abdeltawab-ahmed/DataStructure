#include <iostream>
#include "Single Linked List.cpp"

using namespace std;

void combineNodesBetweenZeros(LinkedList<int>& list) {
    Node<int>* current = list.getHead();
    int sum = 0;
    while (current != NULL && current->next != NULL) {
        if (current->data == 0 && current->next->data != 0) {
            current = current->next;
            sum = 0;
        } else if (current->next->data == 0) {
            current = current->next;
            list.removeAt(list.indexOf(current->data) - 1);
            list.replaceAt(sum + current->data, list.indexOf(current->data) - 1);
            sum = 0;
        } else {
            sum += current->data;
            list.removeAt(list.indexOf(current->data));
        }
        current = current->next;
    }
}

int main() {
    LinkedList<int> list;

    list.insertAtTail(0);
    list.insertAtTail(3);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(0);

    cout << "Original List: ";
    list.print();
    combineNodesBetweenZeros(list);
    cout << "Modified List: ";
    list.print();

    list.clear();

    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(3);
    list.insertAtTail(0);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(0);

    cout << "Original List: ";
    list.print();
    combineNodesBetweenZeros(list);
    cout << "Modified List: ";
    list.print();

    return 0;
}
