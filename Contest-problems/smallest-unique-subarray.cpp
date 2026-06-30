class Solution {
    using ll = long long;

    static constexpr ll MOD=1000000007LL;
    static constexpr ll BASE = 911;
    vector<ll> pref;
    vector<ll> power;
    int n;
    ll getHash(int l, int r){
        ll h=pref[r+1]- pref[l]*power[r-l+1]%MOD;

        h %= MOD;
        if(h<0) h+=MOD;
        return h;
    }

    bool check(int len){
        unordered_map<ll,int> freq;
        for(int i=0; i+len<=n;i++){
            freq[getHash(i,i+len-1)]++;
        }

        for(int i=0;i+len<=n;i++){
            if(freq[getHash(i,i+len-1)]==1) return true;
        }

        return false;

    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n=nums.size();
        pref.resize(n+1,0);
        power.resize(n+1,1);
        for(int i=1;i<=n;i++){
            power[i]=power[i-1]*BASE % MOD;

        }

        for(int i=1;i<=n;i++){
            pref[i]=(pref[i-1]*BASE + nums[i-1] + 1007) % MOD; //this 1007 is just to 
            //avoid 0 and negative numbers. Any constant larger than the minimum possible 
            //value works.

        }

        int lo=1;
        int hi=n;
        int ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
        
    }
};
