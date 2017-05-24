class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[71][71][71];
        memset(dp, -1, sizeof(dp));
        int infty = INT_MAX/2;
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    int cur = grid[i][j];
                    if (j != k) {
                        cur += grid[i][k];
                    }
                    if (i == n-1) {
                        dp[i][j][k] = cur;
                    } else {
                        for (int d1 = -1; d1 <= 1; ++d1) {
                            for (int d2 = -1; d2 <= 1; ++d2) {
                                if (j + d1 < 0 || j + d1 >= m || k + d2 < 0 || k + d2 >= m) {
                                    continue;
                                }
                                dp[i][j][k] = max(dp[i][j][k], cur + dp[i+1][j+d1][k+d2]);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
};