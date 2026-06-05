class Solution {
  private:
    void dfs2(int node, vector<int>& vis,vector<int> adjT[]){
        vis[node]=1;
        for(auto adjnode : adjT[node]){
            if(!vis[adjnode]){
                dfs2(adjnode,vis,adjT);
            }
        }
    }
    void dfs1(int node,stack<int>& st,vector<int>& vis,
    vector<vector<int>>& graph){
        vis[node]=1;
        for(auto adjnode : graph[node]){
            if(!vis[adjnode]){
                dfs1(adjnode,st,vis,graph);
            }
        }
        st.push(node);
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        //order accoridng to finishing time;
        //reverse the edges
        //count the components 
        vector<int> vis(V,0);
        vector<vector<int>> graph(V);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            
        }
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs1(i,st,vis,graph);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it : graph[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,vis,adjT);
            }
        }
        
        return scc;
        
    }
};
