class Solution {
private:
    int f(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp, int n){
        if(ind==n) return 0;
        if(dp[ind][prevInd]!=-1) return dp[ind][prevInd];
        int len=0+f(ind+1,prevInd,nums,dp,n);
        if(prevInd==0 || nums[prevInd-1]<nums[ind]){
            len=max(len,1+f(ind+1,ind+1,nums,dp,n));

        }
        return dp[ind][prevInd]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,nums,dp,n);

    }
};
