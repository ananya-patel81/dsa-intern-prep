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
    bool isMirror(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;

        return (a->val==b->val)&&(isMirror(a->left,b->right))&&(isMirror(a->right,b->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }
};
