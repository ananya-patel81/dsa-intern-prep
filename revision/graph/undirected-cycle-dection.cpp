// USING BFS 

class Solution {  
    bool detect(int node,vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int next : adj[u]){
                if(!vis[next]){
                    vis[next]=1;
                    q.push({next,u});
                }
                else{
                    if(next != parent) return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int m = edges.size();
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        
        
        return false;
    }
};

//USING DFS 
class Solution {
    bool detect(int node,int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(int next : adj[node]){
            if(!vis[next]){
                if(detect(next,node,adj,vis)) return true;
            }
            else{
                if(next != parent) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int m = edges.size();
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};
