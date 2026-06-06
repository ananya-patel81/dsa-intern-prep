class Solution {
// private:
//     int f(int r, int c,vector<vector<int>> & dp,vector<vector<int>>& matrix, int n){
//         if(r==0 && (c>=0 && c<n)){
//             return dp[r][c]=matrix[r][c]; //since no direction above it is possible;
//         }
//         if(c<0 || c>=n) return 1e7;
//         if(dp[r][c]!=-1) return dp[r][c];
//         int dl=matrix[r][c]+f(r-1,c-1,dp,matrix,n);
//         int up=matrix[r][c]+f(r-1,c,dp,matrix,n);
//         int dr=matrix[r][c]+f(r-1,c+1,dp,matrix,n);

//         return dp[r][c]=min(up,min(dl,dr));
        
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i-1][j];
                int dl=1e7;
                if(j>0){
                    dl=matrix[i][j]+dp[i-1][j-1];
                }
                int dr=1e7;
                if(j<n-1){
                    dr=matrix[i][j]+dp[i-1][j+1];
                }

                dp[i][j]=min(down,min(dl,dr));
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
        
    }
};
