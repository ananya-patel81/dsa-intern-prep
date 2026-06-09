class Solution {
private:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string& s, int n, vector<int>& dp) {
        if (i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX;
        for (int ind = i; ind < n; ind++) { // Notice: ind < n
            if (isPalindrome(i, ind, s)) {
                // If the entire remaining substring is a palindrome, 0 cuts are needed for this part
                int cost = (ind == n - 1) ? 0 : 1 + f(ind + 1, s, n,dp);
                mini = min(mini, cost);
            }
        }
        return dp[i]=mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
            for (int ind = i; ind < n; ind++) { // Notice: ind < n
                if (isPalindrome(i, ind, s)) {
                    // If the entire remaining substring is a palindrome, 0 cuts are needed for this part
                    int cost = (ind == n - 1) ? 0 : 1 + dp[ind + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i]=mini;

        }

        return dp[0];
    }
};
