//YOU CAN DO THIS FOR ANY SOURCE GIVEN BY DOING dist[src]=0; instead of dist[0]=0; 


// User function Template for C++
class Solution {
  void dfsTopo(int i, vector<int>& vis,vector<vector<pair<int,int>>>& adj,stack<int>& st){
      vis[i]=1;
      for(auto it : adj[i]){
          int node=it.first;
          if(!vis[node]){
              dfsTopo(node,vis,adj,st);
          }
      }
      
      st.push(i);
  }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){ //made the adjacency list;
            int from=edges[i][0];
            int to=edges[i][1];
            int wt=edges[i][2];
            adj[from].push_back({to,wt});
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsTopo(i,vis,adj,st);
            }
        }
        
        vector<int> dist(V,-1);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            // CRITICAL FIX 1: If the node is unreachable from src (0), 
            // skip processing its adjacent nodes.
            if (dist[node] != -1) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    // CRITICAL FIX 2: Relax the edge if the neighbor is unvisited (-1)
                    // OR if a shorter path is found.
                    if(dist[v] == -1 || dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        return dist;
    }
};
