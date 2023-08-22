#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template<class T>
class ArrayList {
private:
    T list[MAX_SIZE];
    int length;
public:
    ArrayList() {
        length = 0;
    }

    void insert(T element) {
        if (length >= MAX_SIZE) {
            cout << "List overflow" << endl;
            return;
        }
        list[length] = element;
        length++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > length) {
            cout << "Index out of range" << endl;
            return;
        }
        if (length >= MAX_SIZE) {
            cout << "List overflow" << endl;
            return;
        }
        for (int i = length; i > index; i--) {
            list[i] = list[i-1];
        }
        list[index] = element;
        length++;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return T();
        }
        return list[index];
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        for (int i = index; i < length-1; i++) {
            list[i] = list[i+1];
        }
        length--;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return;
        }
        list[index] = newElement;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
            return false;
        }
        return list[index] == element;
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == MAX_SIZE;
    }

    int listSize() {
        return length;
    }

    int maxListSize() {
        return MAX_SIZE;
    }

    void clear() {
        length = 0;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};
