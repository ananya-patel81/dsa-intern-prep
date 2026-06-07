class Solution {
  private:
    int helper(int index,int cap,vector<vector<int>>& dp,vector<int>& val,
    vector<int>& wt){
        if(index==0){
            if(wt[0]<=cap){
                return dp[index][cap]= (cap/wt[index])*(val[index]);
            }
            else return dp[index][cap]=0;
        }
        if(dp[index][cap]!=-1) return dp[index][cap];
        int not_take=0+helper(index-1,cap,dp,val,wt);
        int take=0;
        if(wt[index]<=cap){
            take= val[index]+helper(index,cap-wt[index],dp,val,wt);
        }
        
        return dp[index][cap]=max(not_take,take);
        
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<int> prev(capacity+1,0);
        for(int cap=0;cap<=capacity;cap++){
            if(wt[0]<=cap){
                prev[cap]= (cap/wt[0])*(val[0]);
            }
            else prev[cap]=0;
        }
        
        for(int i=1;i<n;i++){
            for(int cap=0;cap<=capacity;cap++){ //important observation of the order of traversal;
                int not_take= 0+prev[cap];
                int take=INT_MIN;
                if(wt[i]<=cap){
                    take=val[i]+prev[cap-wt[i]];
                }
                prev[cap]=max(not_take,take);
            }
        }
        
        return prev[capacity];
        
    }
};
