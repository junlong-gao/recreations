class Solution {
    /*
    dp[i][v] the smallest edit distance for path end in node i and length v
    min(dp[u][v-1] + d{n[i] == t[v-1]})
    for all u connected to i
    if v == 1
       dp[i][1] = d{n[i] == t[0]}
    */
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        unordered_map<int, vector<int>> nc;
        for (auto &r : roads) {
            nc[r[0]].push_back(r[1]);
            nc[r[1]].push_back(r[0]);
        }
        
        vector<vector<int>> dp(targetPath.size() + 1, vector<int>(names.size(), INT_MAX / 2));
        vector<vector<int>> p(targetPath.size() + 1, vector<int>(names.size(), 0));
        for (int v = 1; v <= targetPath.size(); ++v) {
            for (int i = 0; i < names.size(); ++i) {
                if (v == 1) {
                    dp[v][i] = (names[i] != targetPath[v-1]);
                } else {
                    for (auto c : nc[i]) {
                        int newVal = (names[i] != targetPath[v-1]) + dp[v-1][c];
                        if (dp[v][i] > newVal) {
                            p[v][i] = c;
                            dp[v][i] = newVal;
                        }
                    }
                }
            }
        }
        
        int best = INT_MAX;
        int bestC = 0;
        for (int i = 0; i < names.size(); ++i) {
            if (dp[targetPath.size()][i] < best) {
                best = dp[targetPath.size()][i];
                bestC = i;
            }
        }
        vector<int> ret;
        for (int i = 1; i <= targetPath.size(); ++i) {
            ret.push_back(bestC);
            bestC = p[targetPath.size() - i + 1][bestC];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};