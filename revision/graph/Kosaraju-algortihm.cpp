class Solution {
    void dfs2(int node, vector<int>& vis2, vector<vector<int>>& adjT){
        vis2[node]=1;
        for(int next : adjT[node]){
            if(!vis2[next]){
                dfs2(next,vis2,adjT);
            }
        }
        
    }
    void dfs(int i, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj){
        vis[i]=1;
        for(int next : adj[i]){
            if(!vis[next]){
                dfs(next,st,vis,adj);
            }
        }
        st.push(i);
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        //make the adj list for og graph and Transpose graph
        vector<vector<int>> adj(V);
        vector<vector<int>> adjT(V);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adjT[e[1]].push_back(e[0]);
        }
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        vector<int> vis2(V,0);
        int cnt=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis2[node]){
                cnt++;
                dfs2(node,vis2,adjT);
            }
        }
        
        return cnt;
        
    }
};
