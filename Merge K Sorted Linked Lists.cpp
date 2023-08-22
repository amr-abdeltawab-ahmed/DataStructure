#include <iostream>
#include <vector>
#include <queue>
#include "Single Linked List.cpp"
using namespace std;


LinkedList<int>* mergeKLists(vector<LinkedList<int>*> &lists) {
// Create a priority queue to store the heads of each linked list
// The priority queue will sort the linked lists based on the value of their head node
priority_queue<pair<int, Node<int>*>, vector<pair<int, Node<int>*>>, greater<pair<int, Node<int>*>>> pq;
for (int i = 0; i < lists.size(); i++) {
if (lists[i]->linkedListSize() > 0) {
pq.push(make_pair(lists[i]->retrieveAt(0), lists[i]->getHead()));
}
}

// Create a new linked list to store the merged list
LinkedList<int> *mergedList = new LinkedList<int>();

// Continue the loop until the priority queue is empty
while (!pq.empty()) {
// Get the head node of the linked list with the smallest value
Node<int>* current = pq.top().second;
int val = pq.top().first;
pq.pop();

// Add the node to the merged list
mergedList->insertAtTail(val);

// Move to the next node in the linked list
if (current->next != NULL) {
pq.push(make_pair(current->next->data, current->next));
}
}

return mergedList;
}

int main() {
    // Create the linked lists
    LinkedList<int> *list1 = new LinkedList<int>();
    list1->insertAtTail(1);
    list1->insertAtTail(4);
    list1->insertAtTail(5);

    LinkedList<int> *list2 = new LinkedList<int>();
    list2->insertAtTail(1);
    list2->insertAtTail(3);
    list2->insertAtTail(4);

    LinkedList<int> *list3 = new LinkedList<int>();
    list3->insertAtTail(2);
    list3->insertAtTail(6);

    // Merge the linked lists
    vector<LinkedList<int>*> lists = {list1, list2, list3};
    LinkedList<int> *mergedList = mergeKLists(lists);

    // Print the merged list
    Node<int> *current = mergedList->getHead();
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
