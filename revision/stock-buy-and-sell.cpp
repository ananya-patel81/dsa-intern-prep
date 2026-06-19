class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_prof=0;
        int mini=prices[0];
        for(int i=0;i<n;i++){
            mini=min(prices[i],mini);
            int cost=prices[i]-mini;
            max_prof=max(max_prof,cost);
        }
        return max_prof;
        
    }
};
