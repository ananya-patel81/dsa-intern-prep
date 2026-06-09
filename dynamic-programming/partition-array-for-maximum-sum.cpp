class Solution {
// private:
//     int f(int i, int n, int k, vector<int>& arr, vector<int>& dp){
//         if(i==n) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int len=0;
//         int maxi=INT_MIN;
//         int globalmaxi=INT_MIN;
//         for(int ind=i;ind<min(n,i+k);ind++){
//             len++;
//             maxi=max(maxi,arr[ind]);
//             globalmaxi=max(globalmaxi,(len*maxi)+f(ind+1,n,k,arr,dp));
//         }
//         return dp[i]=globalmaxi;
//     }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxi=INT_MIN;
            int globalmaxi=INT_MIN;
            for(int ind=i;ind<min(n,i+k);ind++){
                len++;
                maxi=max(maxi,arr[ind]);
                globalmaxi=max(globalmaxi,(len*maxi)+dp[ind+1]);
            }
            dp[i]=globalmaxi;
        }

        return dp[0];
        
    }
};
