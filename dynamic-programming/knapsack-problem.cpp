class Solution {
//   private:
//     int f(int ind,int cap,vector<int>& val,vector<int>& wt,
//     vector<vector<int>>& dp, int n){
//         if(ind==0){
//             if(wt[0]<=cap) return dp[ind][cap]=val[0];
//             else return 0;
//         }
//         if(cap==0){
//             return dp[ind][cap]=0;
//         }
//         if(dp[ind][cap]!=-1) return dp[ind][cap];
//         int not_take= 0+f(ind-1,cap,val,wt,dp,n);
//         int take=INT_MIN;
//         if(wt[ind]<=cap){
//             take=val[ind]+f(ind-1,cap-wt[ind],val,wt,dp,n);
//         }
        
//         return dp[ind][cap]=max(not_take,take);
//     }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // we keep a dp to know the amount collected, by the time
        //we reach the house index, with weight limit wt;
        int n=val.size();
        // vector<vector<int>> dp(n,vector<int>(W+1,-1));
        // for(int i=0;i<n;i++){
        //     dp[i][0]=0; // kyuki agar capacity 0 hai toh kuch nahi le sakte;
        // }
        // for(int cap=1;cap<=W;cap++){
        //     if(wt[0]<=cap) dp[0][cap]=val[0];
        //     else dp[0][cap]=0;
        // }
        
        // for(int i=1;i<n;i++){
        //     for(int cap=1;cap<=W;cap++){
        //         int not_take=0+dp[i-1][cap];
        //         int take=INT_MIN;
        //         if(wt[i]<=cap){
        //             take=val[i]+dp[i-1][cap-wt[i]];
        //         }
        //         dp[i][cap]=max(not_take,take);
        //     }
        // }
        vector<int> prev(W+1,0);  //SINGLE ROW SPACE OPTIMIZATION! 
        for(int cap=0;cap<=W;cap++){
            if(wt[0]<=cap) prev[cap]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int cap=W;cap>=0;cap--){
                int not_take=0+prev[cap];
                int take=INT_MIN;
                if(wt[i]<=cap){
                    take=val[i]+prev[cap-wt[i]];
                }
                prev[cap]=max(not_take,take);
            }
        }
        return prev[W];
    }
};
