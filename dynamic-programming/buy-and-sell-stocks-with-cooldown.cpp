class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>front1(2,0); 
        vector<int>front2(2,0);
        vector<int>curr(2,0);  // rows= indices, columns= buy, not buy
        
        for(int i=n-1;i>=0;i--){
            
                
            int buys= -prices[i]+front1[0];
            int not_buys= 0+front1[1];
            curr[1]=max(buys,not_buys);
            
                
                    
            int sell=prices[i]+front2[1];

            int not_sell=0+front1[0];
            curr[0]=max(sell,not_sell);
            front2=front1;
            front1=curr;
                
            
        }
        return front1[1];
        
        
    }
};
