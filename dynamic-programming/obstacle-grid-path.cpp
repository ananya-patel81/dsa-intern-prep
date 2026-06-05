class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    curr[j]=0;
                    continue;

                } 
                else if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                } 
                int up=0;
                int left=0;

                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=curr[j-1];
                }

                curr[j]=up+left;
            }

            prev=curr;
        }
        return prev[n-1];
    }
};
