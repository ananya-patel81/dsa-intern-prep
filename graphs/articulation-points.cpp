// User function Template for C++

class Solution {
  private:
    int timer=0;
    void dfs(int node, int parent,vector<int> adj[],vector<int>&vis,
    vector<int>& tin, vector<int>& low, vector<int>& mark){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        int cnt=0;
        for(int adjnode : adj[node]){
            if(adjnode == parent) continue;
            if(!vis[adjnode]){
                dfs(adjnode,node,adj,vis,tin,low,mark);
                
                low[node]=min(low[node],low[adjnode]);
                if(low[adjnode]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                cnt++;
            }
            else{
                low[node]=min(low[node], tin[adjnode]);
            }
        }
        if(cnt>1 && parent==-1){
            mark[node]=1;
        }
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> tin(V,0);
        vector<int> low(V,0);
        vector<int> vis(V,0);
        vector<int> ans;
        vector<int> mark(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,mark);
            }
        }
        
        for(int i=0;i<V;i++){
            if(mark[i]==1) ans.push_back(i);
            
        }
        if(ans.size()>0) return ans;
        return {-1};
    }
};
