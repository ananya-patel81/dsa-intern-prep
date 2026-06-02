class Solution {
  private:
    bool dfsCheck(int node,vector<vector<int>> &adj,vector<int>& vis, vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(dfsCheck(nbr,adj,vis,pathvis)==true) return true;
            }
            else if(pathvis[nbr]==1){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathvis)==true) return true;
            }
        }
        
        return false;
    }
};
