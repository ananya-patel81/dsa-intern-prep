class Solution {
private:
    int f(int i,int j, string& word1, string& word2,vector<vector<int>>& dp ){
        if(i==0) return j; // jo word2 mein bache woh add kardo
        if(j==0) return i; //jo word1 mein bache woh delete kardo
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return dp[i][j]= f(i-1,j-1,word1,word2, dp);
        
        return dp[i][j]= 1+ min(f(i-1,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i,j-1,word1,word2,dp)));
        

    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2,dp);
        
    }
};
