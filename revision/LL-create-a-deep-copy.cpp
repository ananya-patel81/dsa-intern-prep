/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertcopies(Node* head){
        Node* temp=head;
        
        while(temp!=NULL){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            
            temp=temp->next->next;

        }
    }

    void insertRandom(Node* head){
        Node* temp=head;
        //copynode->random=temp->random->next;
        while(temp!=NULL){
            Node* copynode=temp->next;
            if(temp->random!=NULL){
                copynode->random=temp->random->next;
            }
            else copynode->random=nullptr;
            temp=temp->next->next;
        }
    }

    Node* getcopy(Node* head){
        Node* dummyhead=new Node(-1);
        Node* res=dummyhead;
        Node* temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            Node* copynode=temp->next;
            temp->next=copynode->next;
            res=res->next;
            temp=temp->next;
            
        }
        return dummyhead->next;
    }
public:
    Node* copyRandomList(Node* head) {
        insertcopies(head);
        insertRandom(head);
        return getcopy(head);
        
    }
};
