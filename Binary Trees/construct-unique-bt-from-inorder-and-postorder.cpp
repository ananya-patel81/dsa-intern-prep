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
    TreeNode* buildBinaryTree(vector<int>& postorder, int postStart, int postEnd,vector<int>& inorder,int inStart, int inEnd,map<int,int>& InMap){
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root=new TreeNode(postorder[postEnd]);

        int inRoot= InMap[root->val];
        int numsLeft= inRoot-inStart;

        root->left= buildBinaryTree(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,InMap);
        root->right= buildBinaryTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,InMap);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> InMap;
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]]=i;
        }
        
        return buildBinaryTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,InMap);
        
    }
};
