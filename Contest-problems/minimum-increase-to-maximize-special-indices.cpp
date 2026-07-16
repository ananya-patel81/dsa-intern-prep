class Solution {
    long long f(int pos, bool skip,vector<vector<long long>>& dp,vector<int>& nums){
        int n = nums.size();
        if(pos>=n-1) return 0;
        if(dp[skip][pos]!=-1) return dp[skip][pos];
        long long ans = max(0,max(nums[pos-1],nums[pos+1])+1-nums[pos]);
        if(skip){
            return dp[skip][pos]=ans+f(pos+2,skip,dp,nums);
        }
        dp[1][pos] = ans + f(pos+3,true,dp,nums);
        dp[0][pos]= ans + f(pos+2,false,dp,nums);

        return min(dp[1][pos],dp[0][pos]);
    }
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        if(n%2){
            for(int i =1;i<n-1;i+=2){
                ans+=max(0,max(nums[i-1],nums[i+1])+1-nums[i]);
            }
            return ans;
        }
        vector<vector<long long>> dp(2,vector<long long>(n,-1));
        return min(f(1,false,dp,nums),f(2,true,dp,nums));

        
    }
};
