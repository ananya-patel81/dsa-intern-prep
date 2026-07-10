class DisjointSet{
    vector<int> parent, rank,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
    }
    
    int findUParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUParent(parent[u]);
    }
    
    void UnionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void UnionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            
        }
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> my_edges(edges.size());
        for(auto& e : edges){
            int u = e[0];
            int v=e[1];
            int wt=e[2];
            my_edges.push_back({wt,{u,v}});
        }
        sort(my_edges.begin(),my_edges.end());
        DisjointSet ds(V+1);
        int sum=0;
        for(auto& e : my_edges){
            int u=e.second.first;
            int v=e.second.second;
            int wt=e.first;
            if(ds.findUParent(u)==ds.findUParent(v)){
                continue;
            }
            ds.UnionBySize(u,v);
            sum+=wt;
        }
        
        return sum;
    }
};
