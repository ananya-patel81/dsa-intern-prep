class Solution {
    bool f(int ind, int sum,vector<int>& arr,vector<vector<int>>& dp){
        if(ind<0) return false;
        if(sum<0) return false;
        if(sum==0) return true;
        if(ind==0) return (arr[ind]==sum);
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool not_take = f(ind-1, sum, arr, dp);
        bool take = false;
        if(arr[ind]<=sum){
            take = f(ind-1, sum-arr[ind],arr, dp);
        }
        return dp[ind][sum]= (not_take || take);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1, sum, arr, dp);
        
    }
};
