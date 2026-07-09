class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int N = dist.size();
        for(int via=0;via<N;via++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(dist[i][via]!=1e8 && dist[via][j]!=1e8) dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        //To detect negative cycles if there had been;
        // for(int i=0;i<N;i++){
        //     if(cost[i][i]<0) return {-1};
        // }
        
    }
};
