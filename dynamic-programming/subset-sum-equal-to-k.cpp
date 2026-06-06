class Solution {
  private:
    bool f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(ind<0) return false;
        if(target<0) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        if(target==0) return true;
        if(ind==0) return (target==arr[0]);
        bool not_take=f(ind-1,target,arr,dp);
        bool take=false;
        if(target>=arr[ind]){
            take=f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=(not_take || take);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int ind=n-1;
        int target=sum;
        return f(ind,target,arr,dp);
        
        
        
    }
};
