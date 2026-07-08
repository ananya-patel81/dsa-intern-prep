class Solution {
    bool detect(int node, int col, vector<int>& color,vector<vector<int>>& graph ){
        color[node]=col;
        for(int next : graph[node]){
            if(color[next]==-1){
                if(!detect(next,!col,color,graph)) return false;
            }
            else{
                if(color[next]==col) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N,-1);
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                if(detect(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};
