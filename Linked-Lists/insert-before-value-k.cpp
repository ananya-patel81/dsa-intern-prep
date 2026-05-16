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
    Node* insertAtK(Node* head, int val, int k){
        
        if(k==head->data){
            Node* temp=new Node(val);
            temp->next=head;
            return temp;
        }
        Node* current= head;
        int cnt=0;
        while(current->next!=NULL){
            cnt++;
            if(current->next->data==k){
                Node* temp=new Node(val, current->next);
                current->next=temp;
                break;
            }
            
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
    Node* head= new Node(10);
    head->next=new Node(20);
    head->next->next= new Node(30);
    
    Solution obj;
    head = obj.insertAtK(head,100,10);
    obj.printList(head);
    
    return 0;
}
