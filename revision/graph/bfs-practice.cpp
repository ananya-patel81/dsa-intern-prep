class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int N = adj.size();
        queue<int> q;
        vector<int> vis(N,0);
        q.push(0);
        vis[0]=1;
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int next : adj[node]){
                if(!vis[next]){
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
        
        return ans;
    }
};
