# DataStructure

These Project include: 
1- Array-Based List with the following methods:
  o insert (elementType element) : void
  o  insertAt (elementType element, int index) : void
  o retrieveAt (int index): elementType
  o removeAt (int index): void
  o replaceAt (elementType newElement, int index)
  o isItemAtEqual (elementType element, int index) : bool
  o isEmpty () : bool
  o isFull () : bool
  o listSize () : int
  o maxListSize (): int
  o clear (): void
  o print () : void

2-  a Single Linked List with the following methods:
  o insertAtHead (elementType element) : void
  o insertAtTail (elementType element) : void
  o insertAt (elementType element, int index) : void
  o removeAtHead () : void
  o removeAtTail () : void
  o removeAt (int index) : void
  o retrieveAt (int index): elementType
  o replaceAt (elementType newElement, int index)
  o isExist (elementType element) : bool
  o isItemAtEqual (elementType element, int index) : bool
  o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
    swapping data.
  o isEmpty () : bool
  o linkedListSize () : int
  o clear (): void
  o print () : void
  
3- a Doubly Linked List with the following methods:
  o insertAtHead (elementType element) : void
  o insertAtTail (elementType element) : void
  o insertAt (elementType element, int index) : void
  o insertAfter (* prev_node, int data) : void
  o removeAtHead () : void
  o removeAtTail () : void
  o removeAt (int index) : void
  o retrieveAt (int index): elementType
  o replaceAt (elementType newElement, int index)
  o isExist (elementType element) : bool
  o isItemAtEqual (elementType element, int index) : bool
  o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
    swapping data.
  o reverse () : void //reverse the data in the double linked list
  o isEmpty () : bool
  o doubleLinkedListSize () : int
  o clear (): void
  o forwardTraversal () : void //Print from head to tail
  o backwardTraversal () : void //Print from tail to head

4- a Circular Linked List with the following methods:
  o insertAtHead (elementType element) : void
  o insertAtEnd (elementType element) : void
  o insertAt (elementType element, int index) : void
  o removeAtHead () : void
  o removeAtEnd () : void
  o removeAt (int index) : void  
  o retrieveAt (int index): elementType
  o replaceAt (elementType newElement, int index)
  o isExist (elementType element) : bool
  o isItemAtEqual (elementType element, int index) : bool
  o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
    swapping data.
  o isEmpty () : bool
  o circularLinkedListSize () : int
  o clear (): void
  o print () : void

5- a Stack with the following methods:
  o push (elementType element) : void
  o pop () : elementType element //return the first element and remove it.
  o top () : elementType element //return the first element without removing it.
  o isEmpty () : bool
  o stackSize () : int
  o clear (): void
  o print () : void


6- a Queue with the following methods:
  o enqueue (elementType element) : void
  o dequeue () : elementType element //return the first element and remove it.
  o first () : elementType element //return the first element without removing it.
  o isEmpty () : bool
  o queueSize () : int
  o clear (): void
  o print () : void

----------------------------------------------------------------------------------------------------


A- By using the previous implemented Linked List, There are 2 Problems:

1. Combine Nodes Between Zeros
   You are given a head of a linked list containing a sequence of integers
    separated by 0s.
   The value presented at the linked list's beginning and end is 0.
   Merge all nodes between any two consecutive 0s into a single node whose
    value is the total of all the merged nodes.
   There are no two consecutive nodes with value == 0.
   There should be no 0s in the new list.
   Example:
  If the Input is the head of the following Linked List: [0, 3, 1, 0, 4, 5, 2, 0],
  Then the Linked List will: [4, 11]
  If the Input is the head of the following Linked List: [0, 1, 0, 3, 0, 2, 2, 0],
  Then the Linked List will: [1, 3, 4]

2. Merge K Sorted Linked Lists
   You have k linked-lists, each linked-list is sorted in ascending order.
   You need to merge all the given linked-lists into one sorted linked-list then return it.
   Example:
  If the Input is an array of pointers storing the head nodes of following the
  linked lists: [1, 4, 5], [1, 3, 4], [2, 6].
  Then the Output Linked List will be: [1, 1, 2, 3, 4, 4, 5, 6]
  If the Input is an array of pointers storing the head nodes of following the
  linked lists: [1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10].
  Then the Output Linked List will be: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].


----------------------------------------------------------------------------------------------------


B- By using the previous implemented Stack, There are 2 Problems:

1. Convert the Infix Expression to Postfix Expression
   Infix expression: The expression of the form “a operator b” (a + b) i.e.,
  when an operator is in-between every pair of operands.
   Postfix expression: The expression of the form “a b operator” (ab+) i.e.,
  When every pair of operands is followed by an operator.
   You have a string of an infix expression as an input and you need to return
  its postfix expression.
   Example:
  If the Input is: X^Y / (5*Z) + 2
  Then the output will be: XY^5Z*/2+
  If the Input is: A + B * C + D
  Then the output will be: A B C * + D +
  If the Input is: (A + B) * (C + D)
  Then the output will be: A B + C D + *

2. Longest Valid Parentheses
   You will have a string containing just the characters '(' and ')' as an input.
   You have to return the length of the longest valid (well-formed)
  parentheses substring (A substring is a contiguous non-empty sequence of
  characters within a string.).
   Example:
  If the Input is: ‘(()’
  Then the Output will be: 2 – as the longest valid parentheses are ().
  If the Input is: ‘’
  Then the Output will be: 0.
  If the Input is: ‘)()())’
  Then the Output will be: 4 – as the longest valid parentheses are ()().


----------------------------------------------------------------------------------------------------

C- By using the previous implemented Queue solve the following problems:

1. Generate Binary Numbers from 1 to N
   Write a function that generates and prints all binary integers from 1 to N.
   Example:
  If the Input is: 3
  Then the output will be: 1 10 11
  If the Input is: 5
  Then the output will be: 1 10 11 100 101


2. Implement a Stack
   You need to design a stack that supports push and pop operations using the enqueue and dequeue operations of the queue.
   You can use one or more queue.


4. Sorting a Queue
   You will have a queue with random integer elements as an input.
   You have to sort it.
   Example:
  If the Input is a queue that have: 3 15 2 4
  Then you will modify it to be: 2 3 4 15
  If the Input is a queue that have: 9 1 2 1
  Then you will modify it to be: 1 1 2 9

