class Solution {
  private:
    bool hasCycle(int u,vector<int> adj[],vector<int>& vis){
        vis[u]=1;
        queue<pair<int,int>> q;
        q.push({u,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto nbr: adj[node]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push({nbr,node});
                }
                else{
                    if(nbr!=parent) return true;
                }
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
                if(hasCycle(i,adj,vis)) return true;
            }
        }
        return false;
        // Code here
        
    }
};
