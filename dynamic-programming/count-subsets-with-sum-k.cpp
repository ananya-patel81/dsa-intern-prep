class Solution {
  private:
    int f(int ind,int target,vector<vector<int>>& dp,
    vector<int>& arr,int n){
        if(ind==0){
            if(target==0 && arr[0]==0) return 2; //as take and no take 
            //dono mein satisfy karega;
            if(target==0 || arr[0]==target) return 1; //jab dono equal na do;
            //and khali take ya non take se hi answer aayega;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=f(ind-1,target,dp,arr,n);
        int take=0;
        if(target>=arr[ind]){
            take=f(ind-1,target-arr[ind],dp,arr,n);
        }
        
        return dp[ind][target]=take+not_take;
        
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,dp,arr,n);
        
        
        
        
        
    }
};
