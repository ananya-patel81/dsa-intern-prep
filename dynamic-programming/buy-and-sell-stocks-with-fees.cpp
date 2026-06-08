class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>after (2,0); 
        vector<int>curr(2,0);// rows= indices, columns= buy, not buy
        
        for(int i=n-1;i>=0;i--){
            
                
            int buys= -prices[i]+after[0];
            int not_buys= 0+after[1];
            curr[1]=max(buys,not_buys);
                
                
            int sell=prices[i]+after[1]-fee;
            int not_sell=0+curr[0];
            curr[0]=max(sell,not_sell);

            after=curr;
                
            
        }
        return after[1];
        
    }
};
