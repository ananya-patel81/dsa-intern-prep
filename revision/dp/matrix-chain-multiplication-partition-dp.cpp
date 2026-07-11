class Solution {
    // int f(int i, int j,vector<vector<int>>& dp,vector<int> &arr  ){
    //     if(i==j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int mini=INT_MAX;
    //     for(int k=i;k<j;k++){
    //         int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,dp,arr)+f(k+1,j,dp,arr);
    //         mini=min(mini,steps);
    //     }
    //     return dp[i][j]=mini;
    // }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(n,0));
        // return f(1,n-1,dp,arr);
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>0;i--){
            for(int j=i+1;j<n;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int steps = arr[i-1]*arr[k]*arr[j]+ dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
            
        }
        return dp[1][n-1];
        
    }
};
