class Solution {
    int f(int ind, int n, vector<vector<int>>& dp, vector<int>& price){
        if(ind==0){
            if(n%(ind+1)==0) return price[0]* (n/(ind+1));
            else return 0;
        }
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[ind][n]!=-1) return dp[ind][n];
        int not_take = 0+f(ind-1, n, dp,price);
        int take = INT_MIN;
        if(ind+1 <= n){
            take = price[ind] + f(ind, n-(ind+1), dp, price);
        }
        return dp[ind][n]=max(not_take,take);
    }
  public:
    int cutRod(vector<int> &price) {
        int n= price.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return f(n-1, n, dp, price);
        
        
        
    }
};
