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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto& stone : stones){
            maxrow=max(maxrow,stone[0]); //the number of rows is maxrow+1;
            maxcol=max(maxcol,stone[1]); // the number of colums is maxcol+1;
        }
        DisjointSet ds(maxrow+maxcol+1); // we are assuming 0-based indexing
        // and +1 extra for safety;
        for(auto it : stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBySize(noderow,nodecol);

        }

        int cnt=0; //to keep count of valid components.
        for(int i=0;i<maxrow+maxcol+1;i++){
            if(ds.parent[i]==i && ds.size[i]>1) cnt++;
        }
        int ans=stones.size()-cnt;
        return ans;
        
    }
};
