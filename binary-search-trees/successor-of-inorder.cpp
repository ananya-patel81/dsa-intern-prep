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
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        
        Node* successor=NULL;
        while(root!=NULL){
            if(root->data<=k->data){
                root=root->right;
            }
            else{
                successor=root;
                root=root->left;
            }
        }
        if(successor==NULL) return -1;
        
        return successor->data;
        
    }
};
