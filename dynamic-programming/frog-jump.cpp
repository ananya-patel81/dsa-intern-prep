class Solution {
//   private:
//     int helper(int index,vector<int>& dp, vector<int>& height){
//         if(index==0){
//             dp[index]=0;
//             return dp[index];
//         }
//         if(dp[index]!=-1){
//             return dp[index];
//         }
//         int left=helper(index-1,dp,height)+abs(height[index]-height[index-1]);
//         int right= INT_MAX;
//         if(index>1) right= helper(index-2,dp,height)+abs(height[index]-height[index-2]);
//         return dp[index]=min(left,right);
//     }
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        // helper(n-1,dp,height);
        // return dp[n-1];  This was memoization
        // dp[0]=0;
        // for(int i=1;i<n;i++){
        //     int fs=dp[i-1]+abs(height[i]-height[i-1]);
        //     int ss=INT_MAX;
        //     if(i>1) ss= dp[i-2]+abs(height[i]-height[i-2]);
        //     dp[i]=min(fs,ss);
        // }
        // return dp[n-1];  this was tabulation
        int prev=0; //d[i-2]equivalent 
        int prev2= 0; //d[i-1] equivalent 
        for(int i=1;i<n;i++){
            int fs=prev+abs(height[i]-height[i-1]);
            int ss=INT_MAX;
            if(i>1) ss= prev2+abs(height[i]-height[i-2]);
            int curri= min(fs,ss);
            prev2=prev;
            prev=curri; //for space optimization
        }
        return prev;
         
    }
};
