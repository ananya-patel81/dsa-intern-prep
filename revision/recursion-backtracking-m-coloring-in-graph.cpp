class Solution {
  private:
    bool isValid(int col, int node, vector<vector<int>>& adj,vector<int>& color){
        for(auto next : adj[node]){
            if(color[next]==col) return false;
        }
        return true;
    }
    bool solve(int node,int v,vector<vector<int>> &adj, int m,vector<int>& color) {
        if(node==v){
            return true;
        }
        for(int col=0;col<m;col++){
            if(isValid(col,node,adj,color)){
                color[node]=col;
                if(solve(node+1,v,adj,m,color)) return true;
                color[node]=-1;
            }
        }
        return false;
        
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        vector<int> color(v,-1);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return solve(0,v,adj,m,color);
        
    }
};
