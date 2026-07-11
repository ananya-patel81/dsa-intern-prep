class Solution {
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0 ){
            if(amount%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = f(ind-1, amount, coins,dp);
        int take = 0;
        if(coins[ind]<=amount){ // if is used and not while 
            take = f(ind, amount-coins[ind],coins, dp); // index is not changed!! 
        }
        return dp[ind][amount]= not_take+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1, amount, coins, dp);
        
    }
};
