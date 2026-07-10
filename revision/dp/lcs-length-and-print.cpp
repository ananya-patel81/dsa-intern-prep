#include<bits/stdc++.h>
using namespace std;


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
