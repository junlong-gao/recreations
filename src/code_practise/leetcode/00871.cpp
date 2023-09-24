class Solution {
    using ll = long long;
    /*
     * dp[i][j] = furthest to reach when reaching station i (0 is the starting point: no stations)
                  with j refills
     */
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<vector<ll>> dp(stations.size() + 1, vector<ll>(stations.size() + 1, -1));
        int ret = INT_MAX;
        
        for (int i = 0; i <= stations.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0) {
                    dp[i][j] = (j == 0 ? startFuel : -1);
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                    if (stations[i-1][0] > dp[i-1][j]) {
                        dp[i][j] = -1;
                    }
                } else {
                    if (dp[i-1][j-1] >= stations[i-1][0]) {
                        dp[i][j] = max(dp[i-1][j-1] + stations[i-1][1], dp[i][j]);
                    }
                    if (dp[i-1][j] >= stations[i-1][0]) {
                        dp[i][j] = max(dp[i-1][j], dp[i][j]);
                    }
                }
                
                if (dp[i][j] >= target) {
                    ret = min(ret, j);
                }
            }
        }
        
        if (ret == INT_MAX) {
            return -1;
        }
        return ret;
    }
};