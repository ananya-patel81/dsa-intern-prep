class Solution {
    int f(int ind,int prevInd, int n, vector<int>& arr, vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prevInd]!=-1) return dp[ind][prevInd];
        int not_take = f(ind+1,prevInd,n,arr,dp);
        int take=INT_MIN;
        if(prevInd==0 || arr[prevInd-1]<arr[ind]){
            take= arr[ind]+f(ind+1, ind+1, n,arr,dp);
        }
        return dp[ind][prevInd]= max(not_take,take);
    }
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,n,arr,dp);
    }
};
