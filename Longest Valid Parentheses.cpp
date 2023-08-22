#include "Stack.cpp"
#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    Stack<int> st;
    st.push(-1); // start with -1 to handle edge case where the first character is ')'
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            st.pop();
            if (st.isEmpty()) {
                // no matching '(' for this ')', update starting point
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    cout << longestValidParentheses("(()") << endl; // expected output: 2
    cout << longestValidParentheses("") << endl; // expected output: 0
    cout << longestValidParentheses(")()())") << endl; // expected output: 4
    return 0;
}
