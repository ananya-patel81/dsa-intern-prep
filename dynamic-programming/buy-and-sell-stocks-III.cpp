class Solution {
private:
    // int f(int day,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp, int n){
    //     if(cap==0) return 0;
    //     if(day==n) return 0;
    //     if(dp[day][buy][cap]!=-1) return dp[day][buy][cap];
    //     if(buy){
    //         int buys=-prices[day]+f(day+1,0,cap,prices,dp,n);
    //         int not_buys= 0 + f(day+1,1,cap,prices,dp,n);
    //         return dp[day][buy][cap]=max(buys,not_buys);
    //     }
    //     int sell=prices[day]+f(day+1,1,cap-1,prices,dp,n);
    //     int not_sell=0+f(day+1,0,cap,prices,dp,n);
    //     return dp[day][buy][cap]=max(sell,not_sell);
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int trans=0;trans<4;trans++){
            dp[n][trans]=0;
        }

        for(int day=n-1;day>=0;day--){
            for(int trans=0;trans<4;trans++){
                
                if(trans%2==0){ // buy=1
                    int buys=-prices[day]+dp[day+1][trans+1];
                    int not_buys= 0 + dp[day+1][trans];
                    dp[day][trans]=max(buys,not_buys);
                }
                else{
                    int sell=prices[day]+dp[day+1][trans+1];
                    int not_sell=0+dp[day+1][trans];
                    dp[day][trans]=max(sell,not_sell);
                }

                

            }
           
        }
        return dp[0][0];
        
    }
};
