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
    int getLength(ListNode* head){
        int len=0;
        ListNode* node=head;
        while(node!=NULL){
            len++;
            node=node->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len=getLength(head);
        //cout<<len;
        ListNode* node=head;
        if(node==NULL) return node;
        while(node->next!=NULL){
            node=node->next;
        }
        node->next=head;
        // cout<<head->val;
        ListNode* start=head;
        // cout<<start->val;
        // for(int i=1;i<(len-k);i++){
        //     cout<<i;
        // }
        k=(k%len);
        for(int i=1;i<(len-k);i++){
            start=start->next;
            //cout<<start->val;
        }
        ListNode* newhead=start->next;
        // cout<<newhead->val;
        start->next=nullptr;
        return newhead;

        
    }
};
