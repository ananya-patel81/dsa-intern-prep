#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;       
    Node* back;     
    Node* next;     

    // Constructor to initialize node with given value
    Node(int value) {
        data = value;
        back = nullptr;
        next = nullptr;
    }
    Node(int value, Node* front, Node* prev){
        data= value;
        back=prev;
        next=front;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Initialize 'prev' to the head node

    // Traverse the array to create the doubly linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Set 'next' of the previous node to the new node
        prev = temp; // Move 'prev' to the new node
    }
    return head;  // Return the head of the doubly linked list
}

Node* deleteAllOccurrencesofK(Node* head, int k){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            if(temp==head){
                head=temp->next;
            }
            Node* prevnode=temp->back;
            Node* nextnode=temp->next;
            if(prevnode!=NULL) prevnode->next=nextnode;
            if(nextnode!=NULL) nextnode->back=prevnode;
            delete temp;
            temp=nextnode;
            
            
        }
        else{
            temp=temp->next;
            
        }
        
    }
    
    return head;
}

void print(Node* head) {
    // Traverse through the list and print each node's data
    while (head != nullptr) {
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;          // Move to the next node
    }
}

int main(){
    vector<int> arr = {12, 5, 8, 5, 4};

    // Convert the array into a doubly linked list
    Node* head = convertArr2DLL(arr);

    // Print the initially created doubly linked list
    cout << "Doubly Linked List Initially: " << endl;
    print(head);
    cout<<"\n"<<endl;
    
    head=deleteAllOccurrencesofK(head,5);
    print(head);
    return 0;
    
}

