class Solution {
// private:
//     int helper(int i1, int i2, string text1, string text2, vector<vector<int>>& dp){
//         if(i1==0 || i2==0) return 0;
//         if(dp[i1][i2]!=-1) return dp[i1][i2];
//         if(text1[i1-1]==text2[i2-1]){
//             return dp[i1][i2]=1+helper(i1-1,i2-1,text1,text2,dp);
//         }
//         return dp[i1][i2]= max(helper(i1-1,i2,text1,text2,dp),helper(i1,i2-1,text1,text2,dp));
//     }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); // for index shifting 
        for(int i=0;i<=n;i++){
            dp[i][0]=0; 
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){ // index shifting 
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);

            }
        }

        return dp[n][m];

        
    }
};
