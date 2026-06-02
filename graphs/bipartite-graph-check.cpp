class Solution {
private:
    bool dfs(int node,int col,vector<vector<int>>& graph, vector<int>& color){
        color[node]=col;
        for(int nbr : graph[node]){
            if(color[nbr]==-1){
                if(dfs(nbr,!col,graph,color)==false) return false;
            }
            else if(color[nbr]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false) return false;
            }
        }
        return true;
        
    }
};
