class Solution {
  private:
    int f(int day,int last,vector<vector<int>>& dp,
    vector<vector<int>>& mat){
        if(dp[day][last]!=-1) return dp[day][last];
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(last!=i){
                    maxi=max(maxi,mat[0][i]);
                }
            }
            return dp[day][last]=maxi;
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,mat[day][i]+f(day-1,i,dp,mat));
            }
        }
        
        return dp[day][last]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,3,dp,mat); //the 3 indicates no previous activity
        
        
    }
};
