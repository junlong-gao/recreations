/* forward search */
class Solution {
public:
    vector<int> cheapestJump(const vector<int>& A, int B) {
        int maxInt = numeric_limits<int>::max();
        vector<int> dp(A.size(), -1);
        vector<int> prev(A.size(), -1);
        vector<int> pathLength(A.size(), 0);

        if(A.empty()) {
          return {};
        }

        dp[0] = A[0];
        pathLength[0] = 1;
        for(int i = 1; i < A.size(); ++i) {
          if(A[i] == -1) continue;
          int cur = maxInt;

          for (int j = max(0, i - B); j < i; ++j) {
              if(dp[j] == -1) {continue;}
              if (dp[j] < cur) {
                cur = dp[j];
                prev[i] = j;
                pathLength[i] = pathLength[j] + 1;
                continue;
              }

              if (dp[j] == cur && (pathLength[i] < pathLength[j] + 1)) {
                prev[i] = j;
                pathLength[i] = pathLength[j] + 1;
                continue;
              }
          }
          if (cur != maxInt) {
            dp[i] = cur + A[i];
          }
        }
        if (prev[A.size() - 1] != -1) {
          vector<int> ret;
          for (int i = A.size() - 1; i >= 0; i = prev[i]) {
            ret.push_back(i + 1);
          }
          reverse(ret.begin(), ret.end());
          return ret;
        }
        return {};
    }
};

/* backward search */
class Solution {
public:
    vector<int> cheapestJump(const vector<int>& A, int B) {
        int maxInt = numeric_limits<int>::max();
        int n = A.size();
        vector<int> dp(n, -1);
        vector<int> next(n, -1);

        if(A.empty() || A.back() == -1) {
          return {};
        }
        
        if (A.size() == 1) {
          return {1};
        }
        
        dp[n - 1] = A[n - 1]; 
        next[n - 1] = -1;
        for(int i = n - 2; i >= 0; --i) {
          if(A[i] == -1) continue;
          int cur = maxInt;
          
          for (int j = i + 1; j < min(n, i + B + 1); ++j) {
              if(dp[j] == -1) {continue;}
              if (dp[j] < cur) {
                cur = dp[j];
                next[i] = j;
                continue;
              }
          }
          
          if (cur != maxInt) {
            dp[i] = cur + A[i];
          }
        }
        
        if (next[0] != -1) {
          vector<int> ret;
          for (int i = 0; i >= 0; i = next[i]) {
            ret.push_back(i + 1);
          }
          return ret;
        } else {
          return {};
        }
    }
};


/*
 *
 * [1,2,4,-1,2]
 * 2
 * [0,0,0,0,0,0]
 * 3
 * [0,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,0]
 * 5
 * [1]
 * 1
 *
 * [1,3,5]
 * [1,2,3,4,5,6]
 * [1,6,7,12,17]
 * [1]
 *
 */
