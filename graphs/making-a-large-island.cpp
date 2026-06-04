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
private:
    bool isValid(int row,int col,int n, int m){
        return (row>=0 && col>=0 && row<n && col<m);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int adjrow=row+dr[i];
                    int adjcol=col+dc[i];
                    if(isValid(adjrow,adjcol,n,n) && grid[adjrow][adjcol]==1){
                        int nodeno=row*n+col;
                        int newnodeno=adjrow*n+adjcol;
                        ds.unionBySize(newnodeno,nodeno);
                    }
                }
            }
        }

        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int adjrow=row+dr[i];
                    int adjcol=col+dc[i];
                    if(isValid(adjrow,adjcol,n,n)){
                        if(grid[adjrow][adjcol]==1){
                            components.insert(ds.findUParent(adjrow*n+adjcol));
                        }
                    }

                }
                int sizetotal=0;
                for(auto it : components){
                    sizetotal+=ds.size[it];

                }
                mx=max(mx,sizetotal+1);
            }
        }

        for(int c=0;c<n*n;c++){
            int row=c/n;
            int col=c%n;
            if(grid[row][col]==1){
                mx=max(mx,ds.size[ds.findUParent(c)]);
            }
        }

        return mx;


        
    }
};
