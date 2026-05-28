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
    TreeNode* buildBinaryTree(vector<int>& preorder, int preStart, int preEnd,vector<int>& inorder,int inStart, int inEnd,map<int,int>& InMap){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot= InMap[root->val];
        int numsLeft= inRoot-inStart;

        root->left= buildBinaryTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,InMap);
        root->right= buildBinaryTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,InMap);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> InMap;
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]]=i;
        }
        
        return buildBinaryTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,InMap);
        
    }
};
