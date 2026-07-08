/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return node;
        }

        if(cloned.find(node)!=cloned.end()){
            return cloned[node]; // so that even if it is visited, it can get connected, 
          //and this way, as this is an undirected graph, even the parents will come part as neighbors. This will work for both directed and 
          //undirected. 
        }

        Node* copy = new Node(node->val);
        cloned[node]=copy;

        for(auto neighbor : node->neighbors){
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
        
    }
};
