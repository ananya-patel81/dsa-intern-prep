class Solution {
  private:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& ls, vector<int>& vis){
        vis[i]=1;
        ls.push_back(i);
        for(int next : adj[i]){
            if(!vis[next]){
                dfs(next,adj,ls,vis);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int N = adj.size();
        vector<int> vis(N,0);
        vector<int> ls;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,ls,vis);
            }
        }
        
        return ls;
        
    }
};
