#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int val, Node* next,Node* back) : data(val), next(next), back(back) {}
    Node(int val) : data(val), next(nullptr), back(nullptr) {}
};

class Solution{
public:
    Node* ReverseDLL(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        
        Node* current=head;
        Node* prevNode=nullptr;
        while(current!=nullptr){
            Node* temp=current->next;
            current->next=current->back;
            current->back=temp;
            prevNode=current;
            current=current->back;
        }
        head=prevNode;
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
    Node* head= new Node(10);
    head->next=new Node(20,nullptr,head);
    head->next->next= new Node(30,nullptr,head->next);
    
    Solution obj;
    head = obj.ReverseDLL(head);
    obj.printList(head);
    
    return 0;
}
