#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val, Node* next) : data(val), next(next) {}
    Node(int val) : data(val), next(NULL) {}
};

class Solution{
public:
    Node* arraytoSLL(vector<int> arr){
        Node* head= new Node(arr[0]);
        int n=arr.size();
        Node* current=head;
        for(int i=1;i<n;i++){
            Node* temp= new Node(arr[i]);
            current->next=temp;
            current=current->next;
        }
        return head;
        
    }
    
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    vector<int> arr={1,2,3,4,8};
    Node* head;
    
    Solution obj;
    head = obj.arraytoSLL(arr);
    obj.printList(head);
    
    return 0;
}
