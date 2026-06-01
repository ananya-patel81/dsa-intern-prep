class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis){
        vis[u]=1;
        for(int i=0; i<adj[u].size();i++){
            if(adj[u][i]==1 && vis[i]!=1){
                dfs(i,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int v=isConnected.size();
        vector<int> vis(v,0);
        for(int j=0;j<v;j++){
            if(vis[j]!=1){
                provinces++;
                dfs(j,isConnected, vis);
            }
        }

        return provinces;

        
    }
};
