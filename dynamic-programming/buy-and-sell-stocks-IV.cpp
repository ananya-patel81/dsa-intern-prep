class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>after(2*k+1,0);
        vector<int> curr(2*k+1,0);

        for(int day=n-1;day>=0;day--){
            for(int trans=0;trans<2*k;trans++){
                
                if(trans%2==0){ // buy=1
                    int buys=-prices[day]+after[trans+1];
                    int not_buys= 0 + after[trans];
                    curr[trans]=max(buys,not_buys);
                }
                else{
                    int sell=prices[day]+after[trans+1];
                    int not_sell=0+after[trans];
                    curr[trans]=max(sell,not_sell);
                }

                

            }
            after=curr;
           
        }
        return after[0];
    }
};
