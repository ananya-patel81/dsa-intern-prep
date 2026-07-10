#include<bits/stdc++.h>
using namespace std;

//iske neeche khali DP table banaane ke liye tabulation and space optimized solution bhi hai 

string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int len = dp[n][m];
    int index= len-1;
    int i=n, j=m;
    string ans="";
    for(int k=0;k<len;k++){
        ans+='$';
    }
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans[index]=s1[i-1];
            index--;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    return ans;

}

//Space optimized
class Solution {
    int f(int ind1, int ind2,vector<vector<int>>& dp, string& text1, string& text2 ){
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1-1]==text2[ind2-1]){
            return dp[ind1][ind2]=1+f(ind1-1, ind2-1, dp,text1, text2);
        }
        return dp[ind1][ind2]= max(f(ind1-1,ind2, dp,text1,text2),f(ind1, ind2-1,dp,text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        // int temp = f(n,m,dp,text1,text2);
        // return temp;
        for(int i=0;i<=m;i++){
            prev[i]=0;
        }
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }

        return prev[m];
        
    }
};

//Tabulation, and recursive duntion bhi hai
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // int temp = f(n,m,dp,text1,text2);
        // return temp;
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
        
    }
};

class Solution {
    int f(int ind1, int ind2,vector<vector<int>>& dp, string& text1, string& text2 ){
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1-1]==text2[ind2-1]){
            return dp[ind1][ind2]=1+f(ind1-1, ind2-1, dp,text1, text2);
        }
        return dp[ind1][ind2]= max(f(ind1-1,ind2, dp,text1,text2),f(ind1, ind2-1,dp,text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,dp,text1,text2);
        
    }
};
