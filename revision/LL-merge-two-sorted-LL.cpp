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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* head=dummy;
        ListNode* head1=list1;
        ListNode* head2=list2;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                dummy->next=head1;
                head1=head1->next;
                dummy=dummy->next;
            }
            else{
                dummy->next=head2;
                head2=head2->next;
                dummy=dummy->next;
            }
        }
        while(head1!=NULL){
            dummy->next=head1;
            head1=head1->next;
            dummy=dummy->next;
        }
        while(head2!=NULL){
            dummy->next=head2;
            head2=head2->next;
            dummy=dummy->next;
        }

        return head->next;
        
    }
};
