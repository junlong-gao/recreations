class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &d : cuboids) {
            sort(d.begin(), d.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(cuboids.size());
        int ans = 0;
        for (int i = 0; i <cuboids.size(); ++i) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};