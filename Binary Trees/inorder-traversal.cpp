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
    void printInTrav(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        printInTrav(root->left,res);
        res.push_back(root->val);
        printInTrav(root->right,res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        printInTrav(root,res);
        return res;
        
        
    }
};
