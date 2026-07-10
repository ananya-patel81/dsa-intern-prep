class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        // vector<vector<int>> dp(n,vector<int>(W+1,0));
        vector<int> prev (W+1,0);
        for(int w=0;w<=W;w++){
            if(wt[0]<=w){
                prev[w]=val[0];
            }
        }
        vector<int> curr(W+1,0);
        for(int i=1;i<n;i++){
            for(int cap=0;cap<=W;cap++){
                int not_take = prev[cap];
                int take=INT_MIN;
                if(cap>=wt[i]){
                    take=val[i]+prev[cap-wt[i]];
                }
                curr[cap]=max(take,not_take);
            }
            prev=curr;
        }
        
        return prev[W];
        
    }
};

//Memoization
class Solution {
    int f(int ind, int cap,vector<vector<int>>& dp, vector<int>& val, vector<int>& wt){
        if(ind==0){
            if(wt[0]<=cap) return val[0];
            else return 0;
        }
        if(dp[ind][cap]!=-1) return dp[ind][cap];
        int not_take= f(ind-1,cap,dp,val,wt);
        int take = INT_MIN;
        if(wt[ind]<=cap){
            take=val[ind]+f(ind-1, cap-wt[ind],dp,val,wt);
        }
        return dp[ind][cap]=max(not_take,take);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        int cap=W;
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return f(n-1,W,dp,val,wt);
        
    }
};

//Tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int w=0;w<=W;w++){
            if(wt[0]<=w){
                dp[0][w]=val[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int cap=0;cap<=W;cap++){
                int not_take = dp[i-1][cap];
                int take=INT_MIN;
                if(cap>=wt[i]){
                    take=val[i]+dp[i-1][cap-wt[i]];
                }
                dp[i][cap]=max(take,not_take);
            }
        }
        
        return dp[n-1][W];
        
    }
};
