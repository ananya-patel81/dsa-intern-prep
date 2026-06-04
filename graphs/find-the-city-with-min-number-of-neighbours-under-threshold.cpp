class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //constructing the graph adjacency matrix. 
        vector<vector<int>> dist(n, vector<int> (n, 1e7));
        
        // Set the distance for each edge
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];  // Set the distance from city1 to city2
            dist[it[1]][it[0]] = it[2];  // Set the distance from city2 to city1
        }
        
        // Set the diagonal to 0, as the distance from a city to itself is 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for(int via=0; via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]==1e7 || dist[via][j]==1e7){
                        continue;
                    }
                    else{
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                    }
                }
            }
        }

        int cntmax=n;
        int cityno=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dist[city][adjcity]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntmax){
                cntmax=cnt;
                cityno=city;
            }


        }

        return cityno;
        
        
    }
};
