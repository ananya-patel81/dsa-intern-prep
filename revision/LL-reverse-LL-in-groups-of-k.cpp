/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseLL(ListNode* head){
        ListNode* node=head;
        ListNode* prev= nullptr;
        while(node!=NULL ){
            ListNode* after=node->next;
            node->next=prev;
            prev=node;
            node=after;
            
        }
        return prev;
        
        

    }

    ListNode* getKthnode(ListNode* head, int k){
        k-=1;
        ListNode* temp=head;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getKthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast) prevlast->next=temp;
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverseLL(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevlast->next=kthnode;
            }
            prevlast=temp;
            temp=nextnode;

        }
        return head;
        
    }
};
