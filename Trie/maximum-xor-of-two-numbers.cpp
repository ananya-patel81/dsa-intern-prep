struct Node{
    Node* links[2]={nullptr};
    bool containsKey(int bit){
        return links[bit];
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMaxXor(int x){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(node->containsKey(1-bit)){
                maxi= maxi | (1<<i);  //to get the max xor value, agar opposite bit hoga, toh answer mein dono opposite bits ka xor 1 aayega, warna 0 hi rahega.
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }

        }

        return maxi;
    }

};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int num : nums){
            trie.insert(num);
        }
        int maxXor=0;
        for(int num : nums){
            maxXor=max(maxXor,trie.getMaxXor(num));
        }

        return maxXor;
        
    }
};
