class Solution {
public:
    int rob(vector<int>& nums) {
        //divide the problem into indexes. 
        //do all the stuff for that index
        //store the max;
        //har index se i+2 jaa sakti hu
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
        
    }
};

//space Optimized 
class Solution {
public:
    int rob(vector<int>& nums) {
        //divide the problem into indexes. 
        //do all the stuff for that index
        //store the max;
        //har index se i+2 jaa sakti hu
        int n=nums.size();
        int prev2=nums[0];
        if(n==1) return nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};
