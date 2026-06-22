class Solution {
    const long long MOD = 1000000007LL;
private:
    long long countGE(long long X,vector<int>& value, vector<int>& decay, int m ) {
        int n=value.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            int a=value[i];
            int d=decay[i];
            if(a<X) continue;
            cnt+= (a-X)/d +1;
            if(cnt>=(long long) m) return cnt;

        }
        return cnt;
    }

    long long sumofap(long long a, long long d, long long k){
        return k*(2*a - (k-1)*d)/2;
    }
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n=value.size();
        long long totalPositiveRewards=0;
        for(int i=0;i<n;i++){
            int a=value[i];
            int d=decay[i];
            if(a<1) continue;
            totalPositiveRewards+= (a-1)/d +1;
            if(totalPositiveRewards> (long long)m) break;
        }

        long long picks= min(totalPositiveRewards,(long long)m);
        if(picks==0) return 0;

        long long lo=1;
        long long hi= 1000000000LL;
        while(lo<hi){
            long long mid=(lo+hi+1)/2;
            if(countGE(mid,value,decay,m)>=picks){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }

        long long T = lo;

        long long used=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            long long a=value[i];
            long long d=decay[i];
            if(a<=T) continue;

            long long k=(a-(T+1))/d + 1; //to get the count of numbers strictly greater than T;
            used+=k;
            long long sum=sumofap(a,d,k);
            ans= (ans+sum)%MOD;
        }

        long long remain=picks-used;
        ans=(ans+(remain%MOD)*(T%MOD))%MOD;
        return (int) ans;



        
        
    }
};
