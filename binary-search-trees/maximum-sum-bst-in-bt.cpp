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
class NodeValue{
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
    NodeValue(int minV, int maxV, int s, bool bst ){
        minVal= minV;
        maxVal=maxV;
        sum=s;
        isBST = bst;
    }
};
class Solution {
private:
    int maxSum=0;

    NodeValue helper(TreeNode* root){
        if(root==NULL){
            return NodeValue(INT_MAX, INT_MIN, 0,true);

        }

        auto left= helper(root->left);
        auto right= helper(root->right);

        if(left.maxVal<root->val && root->val<right.minVal){
            int currentSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currentSum);
            return NodeValue(min(left.minVal,root->val),max(right.maxVal,root->val),currentSum,true);
        }

        return NodeValue(INT_MIN,INT_MAX,0,false);
    }
public:
    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        maxSum=0;
        helper(root);
        return maxSum;
        
    }
};
