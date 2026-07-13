class Solution {
    bool isPal(int i, int j, string& s){
        int l = i ; 
        int k =j ;
        while(l<=k){
            if(s[l]!= s[k]) return false;
            l++;
            k--;
        }
        return true;
    }
    int f(int i, int n,string& s, vector<int>& dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j = i ; j<n;j++){
            if(isPal(i,j,s)){
                int count = 1 + f(j+1, n, s, dp);
                mini=min(count,mini);
            }
        }
        return dp[i]=mini;
    }
  public:
    int palPartition(string &s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return f(0,n,s,dp)-1; //since yeh yaha ek extra ginta hai, like if your s was "a",
        //it'd see "a" as a palindrom and put one partition in front of it and then the 
        //i==n (length of the string) and will return 0 but in total give 1 partition, 
        //even though acc to the format the answer should be 0, so we subtract 1 at the end. 
        
        
    }
};
