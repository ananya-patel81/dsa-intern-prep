class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long apSum(long long a, long long d, long long k) {
        return k * (2 * a - (k - 1) * d) / 2;
    }

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {

        int n = value.size();

        auto countGE = [&](long long T) -> long long {
            long long cnt = 0;

            for (int i = 0; i < n; i++) {
                long long a = value[i];
                long long d = decay[i];

                if (a < T) continue;

                cnt += (a - T) / d + 1;

                if (cnt >= (long long)m)
                    return cnt;
            }

            return cnt;
        };

        // total positive rewards
        long long totalPositive = 0;

        for (int i = 0; i < n; i++) {
            long long a = value[i];
            long long d = decay[i];

            totalPositive += (a - 1) / d + 1;

            if (totalPositive > (long long)m)
                break;
        }

        long long picks = min((long long)m, totalPositive);

        if (picks == 0)
            return 0;

        long long lo = 1;
        long long hi = 1000000000LL;

        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;

            if (countGE(mid) >= picks)
                lo = mid;
            else
                hi = mid - 1;
        }

        long long T = lo;

        long long used = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long a = value[i];
            long long d = decay[i];

            if (a <= T)
                continue;

            long long k = (a - (T + 1)) / d + 1;

            used += k;

            ans = (ans + apSum(a, d, k)) % MOD;
        }

        long long remaining = picks - used;

        ans = (ans + (remaining % MOD) * (T % MOD)) % MOD;

        return (int)ans;
    }
};
