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
        if(head==NULL || head->next==nullptr) return head;
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
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){ //very importantttt
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverseLL(slow->next);
        
        ListNode* first=head;
        ListNode* second = newhead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverseLL(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newhead);
        return true;
    }
};
