#include <iostream>
#include <string>

#include "Queue.cpp"

using namespace std;

void generateBinaryNumbers(int n) {
    Queue<string> q;
    q.enqueue("1");

    for (int i = 1; i <= n; i++) {
        string s1 = q.dequeue();
        cout << s1 << " ";

        string s2 = s1;
        s1 += "0";
        s2 += "1";

        q.enqueue(s1);
        q.enqueue(s2);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    generateBinaryNumbers(n);

    return 0;
}
