// in the input of the edges, the edges[1] pointed to edges[0];
//COURSE SCHEDULE I
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> indegree(V,0);
        for(auto edge : prerequisites){
            indegree[edge[0]]++;
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
            for(auto node : adj[curr]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }

        if(topo.size()==V) return true;
        return false;
        
    }
};

//COURSE SCHEDULE II
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> indegree(V,0);
        for(auto edge : prerequisites){
            indegree[edge[0]]++;
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
            for(auto node : adj[curr]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }

        if(topo.size()== V) return topo;
        return {};
        
    }
};
