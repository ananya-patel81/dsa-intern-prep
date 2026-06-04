// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V;i++){
            for(auto& it : edges){
                int from=it[0];
                int to=it[1];
                int wt=it[2];
                if(dist[from]!=1e8 && dist[from]+wt<dist[to]){
                    dist[to]=dist[from]+wt;
                }
            }
            
        }
        
        for(auto& it : edges){
            int from=it[0];
            int to=it[1];
            int wt=it[2];
            if(dist[from]!=1e8 && dist[from]+wt<dist[to]){
                return {-1};
            }
            
        }
        
        return dist;
    }
};
