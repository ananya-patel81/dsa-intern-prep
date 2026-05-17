#include <bits/stdc++.h>
using namespace std;

// Class representing a node in a doubly linked list
class Node {
public:
    int data;       
    Node* prev;     
    Node* next;     

    // Constructor to initialize node with given value
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Solution class containing methods to manipulate the doubly linked list
class Solution {
public:
    Node* head = nullptr;

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty, set new node as head
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        // Link the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }

    // Function to remove duplicate values from a sorted doubly linked list
    Node* removeDuplicates() {
        if(!head) return nullptr;
        Node* current=head;
        
        while(current!=NULL && current->next!=nullptr){
            
            
            Node* nextnode=current->next;
            while(nextnode!=NULL && nextnode->data==current->data){
                Node* duplicate=nextnode;
                nextnode=nextnode->next;
                delete duplicate;
            }
            Node* distinctNode=nextnode;
            current->next=distinctNode;
            if(distinctNode!=NULL)distinctNode->prev=current;
            current=current->next;
        }
            
            
        
            
        return head;
    }

    // Function to print the list
    void printList() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Solution sol;

    // Initial list values (with duplicates)
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};

    for (int value : values) {
        sol.insertAtEnd(value);
    }

    // Print the original list
    cout << "Original List: ";
    sol.printList();

    // Remove duplicate nodes (keep only one occurrence)
    sol.removeDuplicates();

    // Print the updated list
    cout << "After Removing Duplicates (keeping 1 occurrence): ";
    sol.printList();

    return 0;
}
