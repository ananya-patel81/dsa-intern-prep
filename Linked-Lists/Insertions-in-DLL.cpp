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
    Node* insertBeforeHead(Node* head, int val){
        Node* newNode= new Node(val,head,nullptr);
        head->back=newNode;
        return newNode;
        
    }
    
    Node* insertBeforetail(Node* head, int val){
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* newNode=new Node(val,temp,temp->back);
        temp->back->next=newNode;
        temp->back=newNode;
        return head;
        
    }
    
    void insertBeforeNode(Node* node, int val){
        Node* newNode= new Node(val,node,node->back);
        node->back->next=newNode;
        node->back=newNode;
        
    }
    
    Node* insertAfterNode(Node* head, Node* node, int val){
        Node* prev=node->back;
        Node* front=node->next;
        if(prev==nullptr && front==nullptr){
            Node* newNode= new Node(val,nullptr,node);
            front=newNode;
        }
        if(prev==nullptr){ // I want to add after head.
            Node* newNode= new Node(val,node->next,node);
            
            front->back=newNode;
            front=newNode;
        }
        if(front==nullptr){//I want to add after tail.
            Node* newNode= new Node(val, nullptr,node);
            front=newNode;
            
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp==node){
                break;
            }
            temp=temp->next;
        }
        Node* newNode=new Node(val,node->next,node);
        front->back=newNode;
        node->next=newNode;
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
    head = obj.insertAfterNode(head,head,100);
    obj.printList(head);
    
    return 0;
}
