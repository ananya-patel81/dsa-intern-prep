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
class Compare {
public:
    // Comparator to order ListNode pointers based on node values
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minH;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL) minH.push(lists[i]);
        }

        while(!minH.empty()){
            ListNode* newNode=minH.top();
            ListNode* nextNode=newNode->next;
            tail->next=newNode;
            tail=tail->next;
            minH.pop();
            if(nextNode!=NULL) minH.push(nextNode);


        }

        return dummy->next;



        
    }
};
