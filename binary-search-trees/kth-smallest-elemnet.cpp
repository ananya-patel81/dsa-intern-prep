//For Kth largest, change the limit from (--k==0) to like limit for when n-k is 0, like the kth largest is the (n-k)th smallest;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int inorder(TreeNode* root, int k){
        int result=-1;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                if(--k==0) result=curr->val;;
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    if(--k==0) result= curr->val;
                    curr=curr->right;
                }
            }
        }
        return result;

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthsmall=inorder(root,k);
        return kthsmall;
        
    }
};
