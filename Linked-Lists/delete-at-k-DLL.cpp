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
    Node* deletehead(Node* head){
        if(head==NULL){
            return head;
        }
        if(head->next==nullptr && head->back==nullptr){
            delete head;
            return NULL;
        }
        Node* prev=head;
        head=head->next;
        prev->next=nullptr;
        delete prev;
        return head;
        
    }
    
    Node* deletetail(Node* head){
        if(head==NULL){
            return head;
        }
        if(head->next==nullptr && head->back==nullptr){
            delete head;
            return NULL;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
            
        }
        Node* prev=temp->back;
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return head;
        
        
    }
    
    Node* deleteAtK(Node* head,int k){
        if(head==NULL){
            return head;
        }
        if(head->next==nullptr && head->back==nullptr){
            if(k==1){
                delete head;
                return NULL;
            }
            
            return head;
        }
        int cnt=0;
        Node* temp=head;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                Node* prev=temp->back;
                Node* front=temp->next;
                if(prev==NULL){
                    return deletehead(head);
                }
                if(front==NULL){
                    return deletetail(head);
                }
                else{
                    prev->next=front;
                    front->back=prev;
                    temp->back=nullptr;
                    temp->next=nullptr;
                    delete temp;
                }
                break;
            }
            temp=temp->next;
        }
        return head;
        
    }
    void deletenode(Node* node){ //you cannot delete the head, if you want to, then you'd have to readjust it in the code accordingly and assign the next elelment as the head. 
        if(node==nullptr) return;
        Node* prev=node->back;
        Node* front=node->next;
        if(prev==nullptr){
            if(front!=nullptr){
                front->back=nullptr;
            }
        }
        else{
            prev->next=front;
            if(front!=nullptr){
                front->back=prev;
            }
        }
        node->next=nullptr;
        node->back=nullptr;
        
        delete node;
        
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
    obj.deletenode(head->next);
    obj.printList(head);
    
    return 0;
}
