/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //for accessing back traversal, we keep a parent track
        unordered_map<TreeNode*, TreeNode*> parent_track;
        createParentTrack(root,parent_track);

        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int dis=0;
        while(!q.empty()){
            
            int size=q.size();
            
            if(dis++==k) break;
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

        vector<int> ans;

        while(!q.empty()){
            TreeNode* node=q.front();
            ans.push_back(node->val);
            q.pop();

        }
        
        return ans;
    }
};
