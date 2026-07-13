class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1, 0));
        for(int i =1;i<=n;i++){
            dp[i][1]=i;
        }
        for(int i=1;i<=k;i++){
            dp[1][i]= 1;
        }
        for(int i = 2; i<=n; i++){
            for(int e = 2; e<=k;e++){
                int mini = INT_MAX;
                int l=1, h=i;
                int temp = 0;
                while(l<=h){
                    int mid = (l+h)/2;
                    int left = dp[mid-1][e-1];
                    int right = dp[i-mid][e];
                    temp = 1 + max(left,right);
                    if(left<right){
                        l=mid+1;
                    }
                    else {
                        h=mid-1;
                    }
                    mini = min(mini,temp);
                }
                dp[i][e]=mini;

            }
        }

        return dp[n][k];
    }
};
