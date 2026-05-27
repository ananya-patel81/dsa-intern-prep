/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    bool isleaf(Node* leaf){
        return (leaf->left==NULL && leaf->right==NULL);
    }
    
    void addLeftSide(Node* root, vector<int>& res){
        if(root==NULL) return;
        Node* curr=root->left;
        
        while(curr){
            if(!isleaf(curr)){
                res.push_back(curr->data);
            }
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    void addRightSide(Node* root, vector<int>& res){
        if(root==NULL) return;
        Node* curr=root->right;
        vector<int> temp;
        while(curr){
            if(!isleaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right) curr=curr->right;
            else curr=curr->left;
            
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
        
    }
    
    void addLeaves(Node* root, vector<int>& res){
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
        
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!isleaf(root)) res.push_back(root->data);
        addLeftSide(root,res);
        addLeaves(root,res);
        addRightSide(root,res);
        return res;
        
    }
};
