class Solution {
private: 
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i==0){ //careful with the base condition 
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else return 1e8; //careful here, since you want min;
        } 
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_taken=0+helper(i-1,amount,coins,dp);
        int taken=INT_MAX; //careful here 
        if(amount>=coins[i]){
            taken=1+helper(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=min(taken,not_taken);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)); //careful here 
        int ans= helper(n-1,amount,coins,dp); //carefule with what final dp[][] you want;
        if(ans>=1e8) return -1; //careful here
        return ans;
        
    }
};
