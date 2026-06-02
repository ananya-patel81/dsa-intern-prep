class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        
        
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);
            for(auto node : revGraph[curr]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

        
    }
};
