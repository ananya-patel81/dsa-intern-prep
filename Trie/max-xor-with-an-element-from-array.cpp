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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        for(int i=0;i<queries.size();i++){
            int arri=queries[i][1];
            int xi=queries[i][0];
            int ind=i;
            oQ.push_back({arri,{xi,i}});
        }

        sort(oQ.begin(),oQ.end());
        int q=queries.size();
        vector<int> ans(q,0);
        int ind=0;
        int n=nums.size();
        Trie trie;
        for(int i=0;i<q;i++){
            int ai=oQ[i].first;
            int xi=oQ[i].second.first;
            int qInd=oQ[i].second.second;
            while(ind <n && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qInd]=-1;
            else ans[qInd]=trie.getMaxXor(xi);

        }

        return ans;

        
    }
};
