class Node{
    Node* links[2]={nullptr};
    bool fl=false;

public:
    void putKey(int bit, Node* node){
        links[bit]=node;
    }

    bool containsKey(int bit){
        return links[bit];
    }

    Node* getKey(int bit){
        return links[bit];
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root= new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->putKey(bit, new Node());
            }
            node=node->getKey(bit);
        }
    }

    int getMaxXor(int x){
        Node* node = root;
        int maxXor= 0;
        for(int i=31;i>=0;i--){
            int bit = (x>>i)&1;
            if(node->containsKey(1-bit)){
                maxXor = maxXor | (1<<i) ; 
                node=node->getKey(1-bit);
            }
            else{
                node=node->getKey(bit);
            }
        }
        return maxXor;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n= nums.size();
        for(int num : nums){
            trie.insert(num);
        }
        int maxXor=0;
        for(int i=0;i<n;i++){
            maxXor= max(maxXor,trie.getMaxXor(nums[i]));
        }
        return maxXor;
        
    }
};
