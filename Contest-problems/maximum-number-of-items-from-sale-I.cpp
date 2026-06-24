class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int mn=INT_MAX;
        vector<int> dp(budget+1,0);
        for(auto& item : items){
            mn=min(mn,item[1]);
        }
        for(auto& item : items){
            int factor = item[0];
            int price = item[1];
            int gain=0;
            for(auto& other : items){
                if(other[0]%factor==0){
                    gain++;
                }
            }
            for(int b=budget;b>=price;b--){
                dp[b]=max(dp[b],dp[b-price]+gain);
            }
        }

        int ans=0;
        for(int spent=0;spent<=budget;spent++){
            ans=max(ans,dp[spent]+(budget-spent)/mn);
        }

        return ans;
        
    }
};
