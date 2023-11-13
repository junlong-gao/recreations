class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, const string &s) {
        if (i == j) {
            return 1;
        }
        int &ans = dp[i][j];
        if (ans != -1) {
            return ans;
        }
        if (s[i] == s[j]) {
            ans = solve(i, j-1, s);
            return ans;
        } else {
            ans = INT_MAX;
            for (int k = i; k < j; ++k) {
                ans = min(ans, solve(i, k, s) + solve(k+1, j, s));
            }
            return ans;
        }
    }
public:
    int strangePrinter(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size() - 1, s);
    }
};