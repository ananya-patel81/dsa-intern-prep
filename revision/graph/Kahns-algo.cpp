class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // USING TOPOSORT and BFS logicc KAhn's Algorithm
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                topo.push_back(i);
                q.push(i);
                
            } 
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int next : adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    topo.push_back(next);
                    q.push(next);
                }
            }
        }
        
        return (topo.size()!=V);
        
        
    }
};
