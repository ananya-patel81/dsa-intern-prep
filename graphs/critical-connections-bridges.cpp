class Solution {
private:
    int timer=1;
    void dfs(int node,int parent, vector<int>& vis, vector<vector<int>>& graph,vector<int>& tin,vector<int>& low, vector<vector<int>>& ans){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(int adjnode : graph[node]){
            if(adjnode==parent) continue;
            if(!vis[adjnode]){
                dfs(adjnode,node,vis,graph,tin,low,ans);

                low[node]=min(low[node],low[adjnode]);

                if(low[adjnode]>tin[node]){ // important observation: we compare low[adjnode] with tin[node] and not low[node];
                    ans.push_back({node,adjnode});
                }
            }
            else{
                low[node]=min(low[node],tin[adjnode]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //dfs traversal, with each node having a time and lowest time associated with
        //it. 
        vector<vector<int>> graph(n);
        for(auto& edge : connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<vector<int>> ans;
        dfs(0,-1,vis,graph,tin,low,ans);

        return ans;
        
    }
};
