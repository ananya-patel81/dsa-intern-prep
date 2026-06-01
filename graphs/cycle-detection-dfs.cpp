class Solution {
  private:
    bool dfsCycle(int u,int parent,vector<int> adj[],vector<int>& vis){
        vis[u]=1;
        
        for(auto nbr : adj[u]){
            if(!vis[nbr]){
                if(dfsCycle(nbr,u,adj,vis)) return true;
            }
            else if(nbr!=parent){
                return true;
                
            }
        }
        return false;
      
      
  }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int> adj[V];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfsCycle(i,-1,adj,vis)) return true;
            }
        }
        return false;
        // Code here
        
    }
};
