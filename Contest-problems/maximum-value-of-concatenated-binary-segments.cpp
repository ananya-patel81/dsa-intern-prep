class Solution {
    int mod = 1e9+7;
    long long find(long long base, long long exp){
        long long res = 1;
        while(exp>0){
            if(exp%2==1) res = (res*base)%mod;
            base = base%mod;
            base = (base*base)%mod;
            exp/=2;
        }
        return res%mod;
    }
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        //order according to segment with least number of zeros; 
        int n = nums1.size();
        int last = 0;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            if(nums0[i]==0) last+=nums1[i];
            else a.push_back({nums1[i],nums0[i]});
        }

        sort(a.begin(),a.end(),[](auto& a1, auto& a2){
            if(a1.first==a2.first) return a1.second < a2.second;
            return a1.first>a2.first;
        });
        int exp = 0;
        long long ans = 0;
        int n2 = a.size();
        for(int i = n2-1;i>=0;i--){
            auto [ones,zeros] = a[i];
            exp+=zeros;
            long long val = (find(2,exp)*((find(2,ones)%mod -1)%mod))%mod ;
            ans = (ans+val)%mod;
            exp+=ones;

        }

        long long x = find(2,exp) % mod;
        long long y = find(2,last)%mod;
        long long val = ((x%mod)*(y-1%mod)%mod)%mod;
        ans= (ans+val)%mod;

        return (int) ans;
        
    }
};
