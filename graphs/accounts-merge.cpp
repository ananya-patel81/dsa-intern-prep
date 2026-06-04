class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int parU=findUParent(u);
        int parV=findUParent(v);
        if(parU==parV) return;
        if(rank[parU]<rank[parV]){
            parent[parU]=parV;
        }
        else if(rank[parV]<rank[parU]){
            parent[parV]=parU;
        }
        else{
            parent[parU]=parV;
            rank[parU]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
            
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailnodemap; // mail mapping to parent node;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailnodemap.find(mail)==mailnodemap.end()){
                    mailnodemap[mail]=i;
                }
                else{
                    ds.unionBySize(mailnodemap[mail],i);
                }
            }
        }

        vector<string> mergeMail[n];
        for(auto it : mailnodemap){
            string mail = it.first; //the mail;
            int mainAccount= ds.findUParent(it.second);
            mergeMail[mainAccount].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};
