class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V]; // {node, weight}
        for(auto& edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
            
        }
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        int vis[V];
        for(int i=0;i<V;i++) vis[i]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto& iter : adj[node]){
                int adjnode=iter.first;
                int newWt=iter.second;
                if(vis[adjnode]==0){
                    pq.push({newWt,adjnode});
                }
            }
            
        }
        
        return sum;
    }
};
