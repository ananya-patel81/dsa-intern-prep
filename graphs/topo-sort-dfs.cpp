class Solution {
  private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr,vis,adj,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int> topo;
        while(!st.empty()){
            int front=st.top();
            topo.push_back(front);
            st.pop();
        }
        
        return topo;
    }
};
