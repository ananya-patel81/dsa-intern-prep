// User function Template for C++
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
    bool isValid(int row, int col, int n, int m){
        return (row>=0 && col>=0 && row<n && col<m);
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        
        vector<int> ans;
        for(auto& query : operators){
            int row=query[0];
            int col=query[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjrow=row+drow[i];
                int adjcol=col+dcol[i];
                if(isValid(adjrow,adjcol,n,m)){
                    if(vis[adjrow][adjcol]==1){
                        int newcell=adjrow*m+adjcol;
                        int cell=row*m+col;
                        if(ds.findUParent(newcell)!=ds.findUParent(cell)){
                            cnt--;
                            ds.unionBySize(newcell,cell);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};
