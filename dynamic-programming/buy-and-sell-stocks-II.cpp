class Solution {
private:
    int f(int ind, int buy,vector<int>& prices,vector<vector<int>>& dp, int n ){
        if(ind==n){
            return dp[ind][buy]=0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int buys= -prices[ind]+f(ind+1,0,prices,dp,n);
            int not_buys= 0+f(ind+1,1,prices,dp,n);
            return dp[ind][buy]= max(buys,not_buys);
        }
        int sell=prices[ind]+f(ind+1,1,prices,dp,n);
        int not_sell=0+f(ind+1,0,prices,dp,n);
        return dp[ind][buy]=max(sell,not_sell);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1)); // rows= indices, columns= buy, not buy
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    int buys= -prices[i]+dp[i+1][0];
                    int not_buys= 0+dp[i+1][1];
                    dp[i][j]=max(buys,not_buys);
                }
                else{
                    int sell=prices[i]+dp[i+1][1];
                    int not_sell=0+dp[i+1][0];
                    dp[i][j]=max(sell,not_sell);
                }
            }
        }
        return dp[0][1];
        
    }
};
