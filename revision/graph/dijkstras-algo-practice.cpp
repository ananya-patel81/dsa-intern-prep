class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
            
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node= pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            if(dis != dist[node]) continue;
            for(auto next : adj[node]){
                int w = dis + next.second;
                int nextnode= next.first;
                if(dist[nextnode]>w){
                    dist[nextnode]=w;
                    pq.push({dist[nextnode],nextnode});
                }
            }
            
        }
        return dist;
        
    }
};
