class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int lastIndex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i; // for printing
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
