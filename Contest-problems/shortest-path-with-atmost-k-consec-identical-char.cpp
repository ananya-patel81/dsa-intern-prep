class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]}); 
        }
        const long long INF=1e18;
        using T=tuple<long long,int,int>;
        vector<vector<long long>> dist(n,vector<long long>(k+1,INF)); //to store distance corresponding to node and number of consecutive characters till then.
        priority_queue<T,vector<T>,greater<T>> pq;
        dist[0][1]=0; 
        pq.push({0,0,1}); //cost,node,count;
        while(!pq.empty()){
            auto [dis,node,cnt]=pq.top();
            pq.pop();
            if(dis!=dist[node][cnt]) continue; //like if this is not the shortest one we know, so it doesn't contribute to our search as such. 
            for(auto &[v,w] : adj[node]){
                int newcnt=0;
                if(labels[v]==labels[node]){
                    newcnt=cnt+1;
                    if(newcnt>k) continue;
                }
                else{
                    newcnt=1;
                }
                if(dis+w < dist[v][newcnt]){
                    dist[v][newcnt]=dis+w;
                    pq.push({dis+w,v,newcnt});
                }
            }
        }

        long long ans=INF;
        for(int c=1;c<=k;c++){
            ans=min(ans,dist[n-1][c]);
        }
        return (ans==INF) ? -1 : ans;


        
    }
};
