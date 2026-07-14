class Node{
    Node* links[2]={nullptr};
    bool fl = false;
public:
    bool containsKey(int bit){
        return links[bit];
    }
    void putKey(int bit, Node* node){
        links[bit]=node;
    }
    Node* getKey(int bit){
        return links[bit];
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node= root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1 ; 
            if(!node->containsKey(bit)){
                node->putKey(bit,new Node());
            }
            node=node->getKey(bit);
        }
    }

    int getMaxXor(int x){
        Node* node = root;
        int maxXor=0;
        for(int i=31;i>=0;i--){
            int bit = (x>>i)&1;
            if(node->containsKey(1-bit)){
                node=node->getKey(1-bit);
                maxXor = maxXor | (1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        int q = queries.size();
        for(int i=0;i<q;i++){
            int xi = queries[i][0];
            int mi = queries[i][1];
            int ind = i;
            oQ.push_back({mi,{xi,i}});
        }
        sort(oQ.begin(),oQ.end());
        int ind = 0;
        Trie trie;
        vector<int> ans(q,0);
        for(int i=0;i<q;i++){
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;
            while(ind<n && nums[ind]<=mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qInd]=-1;
            else ans[qInd] = trie.getMaxXor(xi);
        }

        return ans;
        
    }
};
