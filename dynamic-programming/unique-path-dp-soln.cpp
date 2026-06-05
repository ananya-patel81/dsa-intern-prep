class Solution {
// private: //this is for Memoization and recursion[by removing the dp part]
//     int f(int r,int c, vector<vector<int>>& dp,int m, int n){
        
//         if(r>m || c>n || r<0 || c<0){
//             return 0;
//         }
//         if(r==0 && c==0){
//             return dp[r][c]=1;
//         }
//         if(dp[r][c]!=-1) return dp[r][c];
//         int up=f(r-1,c,dp,m,n);
//         int left=f(r,c-1,dp,m,n);
//         return dp[r][c]=up+left;
        
    
//     }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                } 
                int up=0;
                int left=0;

                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }

                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
        
    }
};
