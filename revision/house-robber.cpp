class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n,0); //each index stores max robbery done till there;
        // dp[0]=nums[0]; //pehla ghar pe hai, toh waha tak max toh woh hi hoga na, uss ghar ka 
        // if(n==1) return dp[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        // }
        // return dp[n-1];

        int prev2=nums[0];
        if(n==1) return prev2;
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }

        return prev;

        
    }
};
