class Solution {
    int f(int r, int c,vector<vector<int>>& grid,vector<vector<int>> &dp ){
        int m = grid.size();
        int n = grid[0].size();
        if(r>=m || c>=n || r<0 || c<0){
            return 1e9; //keep in mind to not keep 0 here, warna kyuki hum min kar rahe hai humesha toh woh yeh hi lelega;
        }
        if(r==0 && c==0) return dp[r][c]=grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int up = grid[r][c]+ f(r-1,c,grid,dp);
        int left = grid[r][c] + f(r,c-1,grid,dp);
        return dp[r][c]=min(up,left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
        
    }
};
