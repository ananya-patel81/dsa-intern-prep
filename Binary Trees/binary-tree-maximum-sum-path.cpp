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
    int dfs(TreeNode* root, int& maxsum){
        if(root==NULL) return 0;
        int left=max(0,dfs(root->left,maxsum)); //keeping lower limit as 0 as we might get negative numbers, so no point of carrying them.
        int right=max(0,dfs(root->right,maxsum));
        maxsum=max(maxsum,left+right+root->val);
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {

        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
        
    }
};
