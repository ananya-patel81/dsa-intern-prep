class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // same as finding partition sums with difference d, as like one partition would have the
        // plus sign and the other hte minus sign, and then we "add" them, so same as subtracting two 
        // partition sums. 
        //tabulation way. s1-(s-s1)=d; d+s/2=s1; Therefore we need a partition with sum s1; 
        //table with [index][target] says the count of subsets with sume as target; 
        int n=nums.size();
        int sum=0;
        for(int num : nums) sum+=num;
        if (abs(target) > sum || (target + sum) % 2 != 0) return 0;

        int mysum=(target+sum)/2;
        vector<vector<int>> dp(n,vector<int>(mysum+1,0));
        dp[0][0] = 1; 
        
        // 2. Way to make sum nums[0] by PICKING nums[0]
        if (nums[0] <= mysum) {
            // If nums[0] is 0, this adds another way to dp[0][0], making it 2.
            dp[0][nums[0]] += 1; 
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=mysum;tar++){
                int not_take=dp[ind-1][tar];
                int take=0;
                if(nums[ind]<=tar){
                    take=dp[ind-1][tar-nums[ind]];
                }
                dp[ind][tar]=not_take+take;
            }
        }

        return dp[n-1][mysum];

        
    }
};
