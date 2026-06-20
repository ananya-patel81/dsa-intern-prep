class Solution {
private:
    int f(int r, int c,int m,int n, vector<vector<int>>& dp){
        if(r<0 || c<0 || r>=m || c>=n){
            return 0;
        }
        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int up = f(r-1,c,m,n,dp);
        int left=f(r,c-1,m,n,dp);
        return dp[r][c]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp);
        
    }
};
