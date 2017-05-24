class Solution {
    /*
    dp[i][j][k] = min cost of painting house[i] with color j given max group count k
    0<=i<=n;
    1<=j<=m;
    1<=k<=n;
    | house[i] has color,
        if j == house[i]
           -> min(dp[i-1][j][k], dp[i-1][l][k-1])
           for all l != j
        else 
           -> infty
    | house has no color
        -> min(dp[i-1][j][k] + cost[i][j-1], dp[i-1][l][k-1] + cost[i][j-1])
           for all l != j
     boundaries:
        | dp[i][j][0]
           -> infty
        | dp[0][j][k]
        if (house[i] != 0)
           if j != house[i]
              -> infty
           if k != 1
              -> infty
           -> 0
        else
           if k != 1
              -> infty
           -> cost[0][j-1]
        
    */
    int dp[101][21][101];
    vector<int> h;
    vector<vector<int>> c;
    int infty = INT_MAX/2;
    int n, m;
    
    int solve(int i, int j, int k) {
        int &ans = dp[i][j][k];
        if (ans != -1) {
            return ans;
        }
        
        if (k == 0) {
            return ans = infty;
        }
        
        if (i == 0) {
           if (h[i] != 0) {
               if (j != h[i]) {
                   return ans = infty;
               }
               if (k != 1) {
                   return ans = infty;
               }
               return ans = 0;
           } else {
               if (k != 1) {
                   return ans = infty;
               }
               return c[i][j-1];
           }
        }
        
        ans = infty;
        if (h[i] != 0) {
            if (j != h[i]) {
                return infty;
            } else {
                for (int l = 1; l <= n; ++l) {
                    if (l == j) {
                        ans = min(ans, solve(i-1, j, k));
                    } else {
                        ans = min(ans, solve(i-1, l, k-1));
                    }
                }
            }
        } else {
            for (int l = 1; l <= n; ++l) {
                if (l == j) {
                    ans = min(ans, c[i][j-1] + solve(i-1,j,k));
                } else {
                    ans = min(ans, c[i][j-1] + solve(i-1, l, k-1));
                }
            }
        }
        return ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        swap(h, houses);
        swap(c, cost);
        this->n = n;
        this->m = m;
        int ret = infty;
        for (int l = 1; l <= n; ++l) {
            ret = min(ret, solve(m-1,l,target));
        }
        if (ret >= infty) {
            return -1;
        }
        return ret;
    }
};