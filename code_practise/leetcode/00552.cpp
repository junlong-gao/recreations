class Solution {
    using ll = unsigned long long;
    ll M = 1e9+7;
public:
    int checkRecord(int n) {
        // number of records only with L and P
        vector<ll> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            if (i == 0) {
                dp[i] = 1;
            } else if (i == 1) {
                dp[i] = 2;
            } else if (i == 2) {
                dp[i] = 4;
            } else if (i == 3) {
                dp[i] = 7;
            } else {
                // XXX be careful with subtraction in modulo arithmatics
                dp[i] = (2 * dp[i-1] + M - dp[i-4])%M;
            }
        }
        
        ll ret = dp[n];
        for (int i = 0; i <= n-1; ++i) {
            ret = (ret + (dp[i] * dp[n - i - 1])%M)%M;
        }
        
        return ret;
    }
};
