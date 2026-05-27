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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(temp->val);
            if(p.first->left){
                todo.push({p.first->left,{p.second.first-1,p.second.second+1}});
            }
            if(p.first->right){
                todo.push({p.first->right,{p.second.first+1,p.second.second+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p :nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());   //The insert() function here takes three parameters: vector.insert(position,start_source,end_source). col.end() (The Destination Position): Tells C++ to insert the new elements right at the tail end of col.
            }
            ans.push_back(col);

        }

        return ans;


        
    }
};
