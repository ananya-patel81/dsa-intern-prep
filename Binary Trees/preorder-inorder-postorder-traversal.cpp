#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class containing the traversal function
class Solution {
public:
    // Function to get the Preorder,
    // Inorder and Postorder traversal
    // Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(Node* root) {
        vector<int> pre,in,post;
        stack<pair<Node*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto top_el=st.top();
            st.pop();
            if(top_el.second==1){
                pre.push_back(top_el.first->data);
                st.push({top_el.first,2});
                if(top_el.first->left!=NULL){
                    st.push({top_el.first->left,1});
                }
            }
            
            else if(top_el.second==2){
                in.push_back(top_el.first->data);
                st.push({top_el.first,3});
                if(top_el.first->right!=NULL){
                    st.push({top_el.first->right,1});
                }
            }
            
            else{
                post.push_back(top_el.first->data);
            }
        }
        
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        
        return result;
        
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;
    
    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
