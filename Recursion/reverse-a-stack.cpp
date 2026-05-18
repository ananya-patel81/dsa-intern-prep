#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
        
    }
    int val=s.top();
    s.pop();
    insertAtBottom(s,temp);
    s.push(val);
}
void reverseStack(stack<int>& s){
    if(s.empty()) return;
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,temp);
}

int main() {
    // Create a sample stack
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
