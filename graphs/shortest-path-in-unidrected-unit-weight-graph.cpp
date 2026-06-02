class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(V,-1);
        queue<pair<int,int>> q; // node with its distance from the source;
        q.push({src,0});
        while(!q.empty()){
            int curr=q.front().first;
            int steps=q.front().second;
            dist[curr]=steps;
            q.pop();
            for(auto nbr : adj[curr]){
                if(dist[nbr]==-1){
                    q.push({nbr,steps+1});
                    dist[nbr]=steps+1;
                }
            }
        }
        return dist;
    }
};
