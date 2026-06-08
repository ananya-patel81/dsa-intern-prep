//MEMOIZATION

class Solution {
  private:
    int f(int i,int j,vector<int>& arr, vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int cnt1= f(i,k,arr,dp);
            int cnt2=f(k+1,j,arr,dp);
            int steps=(arr[i-1]*arr[k]*arr[j]);
            mini=min(mini,steps+cnt1+cnt2);
        }
        return dp[i][j]=mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};

//TABULATION WALA
class Solution {
//   private:
//     int f(int i,int j,vector<int>& arr, vector<vector<int>>& dp){
//         if(i==j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int mini=INT_MAX;
//         for(int k=i;k<j;k++){
//             int cnt1= f(i,k,arr,dp);
//             int cnt2=f(k+1,j,arr,dp);
//             int steps=(arr[i-1]*arr[k]*arr[j]);
//             mini=min(mini,steps+cnt1+cnt2);
//         }
//         return dp[i][j]=mini;
//     }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=0;
        
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){ // as j has to be on one right of i
            //and we already took i==j into account in declaring the 
            //base case
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int cnt1= dp[i][k];
                    int cnt2=dp[k+1][j];
                    int steps=(arr[i-1]*arr[k]*arr[j]);
                    mini=min(mini,steps+cnt1+cnt2);
                
                }
                dp[i][j]=mini;
                
            }
        }
        return dp[1][n-1];
    }
};
