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
    TreeNode* getNode(TreeNode* root, int start){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int size=q.size();
            for (int i=0;i<size;i++){
                TreeNode* current=q.front();
                if(current->val==start){
                    return current;

                }
                q.pop();
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                } 


            }

            

        }
        return root;
    }
    void createParentTrack(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent_track){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right]=current;
                q.push(current->right);
            }

        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target=getNode(root,start);
        unordered_map<TreeNode*, TreeNode*> parent_track;
        createParentTrack(root,parent_track);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int dis=0;
        while(!q.empty()){
            
            int size=q.size();
            dis++;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    vis[current->left]=true;
                    q.push(current->left);
                    
                }
                if(current->right && !vis[current->right]){
                    vis[current->right]=true;
                    q.push(current->right);
                    
                }

                if(parent_track[current] && !vis[parent_track[current]]){
                    vis[parent_track[current]]=true;
                    q.push(parent_track[current]);
                }
            }
            
        }

        return dis-1;

        
    }
};
