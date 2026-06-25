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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(head1!=NULL && head2!=NULL){
            ListNode* node= new ListNode();
            node->val=(head1->val+head2->val + carry )%10;
            carry= (head1->val+head2->val + carry)/10;
            dummy->next=node;
            dummy=dummy->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL){
            ListNode* node= new ListNode();
            node->val=(head1->val+ carry )%10;
            carry= (head1->val+ carry)/10;
            dummy->next=node;
            dummy=dummy->next;
            head1=head1->next;
        }

        while(head2!=NULL){
            ListNode* node= new ListNode();
            node->val=(head2->val + carry )%10;
            carry= (head2->val + carry)/10;
            dummy->next=node;
            dummy=dummy->next;
            head2=head2->next;

        }
        while(carry){
            ListNode* node= new ListNode();
            node->val=( carry )%10;
            carry= ( carry)/10;
            dummy->next=node;
            dummy=dummy->next;
        }

        return head->next;
        
    }
};
