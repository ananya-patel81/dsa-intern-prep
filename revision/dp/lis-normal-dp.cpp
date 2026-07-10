class Solution {
// private:
//     int f(int ind,int prevInd,vector<int>& nums,vector<vector<int>>& dp,int n){
//         if(ind==n) return 0;
//         if(dp[ind][prevInd]!=-1) return dp[ind][prevInd];
//         int len=0+f(ind+1,prevInd,nums,dp,n);
        
//         if(prevInd==0 || nums[ind]>nums[prevInd-1]){
//             len=max(len,1+f(ind+1,ind+1,nums,dp,n));
//         }
//         return dp[ind][prevInd]=len;

//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>after(n+1,0);
        vector<int>curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=0;prevInd<n;prevInd++){
                int len=0+after[prevInd];
                if(prevInd==0 || nums[ind]>nums[prevInd-1]){
                    len=max(len,1+after[ind+1]);
                }

                curr[prevInd]=len;
            }
            after=curr;
        }
        return after[0];
        
    }
};
