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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxwid=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            unsigned long long mmin=q.front().second;
            unsigned long long last;
            unsigned long long first;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned long long currInd=q.front().second-mmin;
                q.pop();
                if(i==0) first=currInd;
                if(i==size-1) last=currInd;
                if(node->left){
                    q.push({node->left,2*currInd+1});
                }
                if(node->right){
                    q.push({node->right,2*currInd+2});
                }
                

            }

            maxwid=max(maxwid,static_cast<int>(last-first+1));
            

        }
        return maxwid;
        
    }
};
