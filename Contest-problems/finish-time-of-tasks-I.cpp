class Solution {
private:
    long long dfs(int node){
        if(g[node].empty()){
            return baseTime[node];
        }

        long long earliest=LLONG_MAX;
        long long latest=LLONG_MIN;
        for(int child : g[node]){
            long long time=dfs(child);
            earliest=min(time,earliest);
            latest=max(time,latest);
        }
        long long ownDuration=(latest-earliest)+baseTime[node];
        return latest+ownDuration;
    }
public:
    vector<vector<int>> g;
    vector<int> baseTime;
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTimeIn) {
        baseTime=baseTimeIn;
        g.assign(n,{});
        for(auto &edge : edges){
            g[edge[0]].push_back(edge[1]);
        }
        return dfs(0);
        
    }
};
