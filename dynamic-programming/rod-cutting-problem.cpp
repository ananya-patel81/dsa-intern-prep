// User function Template for C++

class Solution {
//   private:
//     int helper(int ind, int cap, vector<vector<int>>& dp, vector<int>& price){
//         if(ind==0){
//             if(cap>=1){
//                 return dp[0][cap]=cap*price[0];
//             }
//             else return 0;
            
//         }
//         if(dp[ind][cap]!=-1) return dp[ind][cap];
//         int not_take=0+helper(ind-1,cap,dp,price);
//         int take=0;
//         if(cap>=ind+1){
//             take=price[ind]+helper(ind,cap-(ind+1),dp,price);
//         }
//         return dp[ind][cap]=max(not_take,take);
//     }
  public:
    int cutRod(vector<int> &price) {
        // code here
        //can relate to knapsack problem
        //wt for val[i] is i+1 
        int n=price.size(); //n is like the capacity;
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return helper(n-1,n,dp,price);
        
        vector<int> prev(n+1,0);
        for(int cap=0;cap<=n;cap++){
            prev[cap]=cap*price[0];
        }
        for(int i=1;i<n;i++){
            for(int cap=0;cap<=n;cap++){
                int not_take=0+prev[cap];
                int take=0;
                if(cap>=(i+1)){
                    take=price[i]+prev[cap-(i+1)];
                }
                
                prev[cap]=max(not_take,take);
            }
        }
        
        return prev[n];
    }
};
