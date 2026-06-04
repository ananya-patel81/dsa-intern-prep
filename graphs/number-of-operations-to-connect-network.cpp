class DisjointSet{
public:
    vector<int> parent;
    vector<long long> size;
    DisjointSet(int n){
        
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto& edge : connections){
            int u=edge[0];
            int v=edge[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                cntExtras++; //This is to find the extra edges, that can be used later.
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int cntc=0; // to keep count of components;

        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntc++;
        }

        int ans=cntc-1;
        if(cntExtras>=ans) return ans;
        return -1;
        
    }
};
