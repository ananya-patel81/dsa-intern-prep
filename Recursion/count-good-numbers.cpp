#define mod 1000000007
class Solution {
private:
    long long myPow(long long base, long long exp) {
        long long ans=1;
        base = base % mod; // Ensure base is within mod limits
        
        while (exp > 0) {
            // If exp is odd, multiply base with ans
            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
                exp = exp - 1;
            }
            // If exp is even
            else {
                base = (base * base) % mod;
                exp = exp / 2;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long oddind=n/2;
        long long evenind=(n+1)/2;
        long long oddplaces=(long long)myPow(4,oddind);
        long long evenplaces=(long long) myPow(5,evenind);
        return (oddplaces*evenplaces)%mod;
        
    }
};
