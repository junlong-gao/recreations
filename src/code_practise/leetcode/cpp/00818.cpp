/*
> lcg 818
  ✔ Accepted
  ✔ 53/53 cases passed (4 ms)
[WARN] Failed to get submission beat ratio.
*/
/*
Digestion:
To arrive at positin p from origin, we could:
1. go directly at p, that is, p = 2^k - 1 for some k
2. we go past p, then *after some distance*, turn around and start with speed
   1 again.
3. we stop right before passing p. turn around and move back for some distance, and
   turn back towards p again.
*/
class Solution {

    array<int, 10001> dp = array<int, 10001>{INT_MAX};

    int helper(int p) {
       assert(p >= 0);
       if (p == 0) return 0;
       if (dp[p] != INT_MAX) return dp[p];
       int &ans = dp[p];
       // case 1, we go all the way from origin to k acc:
       int acc = 1;
       int cur = 0;
       int count = 0;
       while (cur < p) {
          cur += acc;
          acc *= 2;
          count ++;
       }
       // arrive at p:
       if (cur == p) {
          ans = std::min(ans, count);
          return ans;
       }
       // now we passed point p, turn around, reduce to subproblem
       ans = std::min(ans, count + 1 + helper(cur - p));

       // case 2, we go directly before p without passing it:
       // then turn around move for j >= 0 times, and turn back towards p again.
       if (count == 1) return ans;
       acc /= 2;
       cur -= acc;
       int j = 0;
       int d = 0;
       while (d <= p) {
          ans = std::min(ans, count + j + 1 + helper(p - (cur - d)));
          j++;
          d = d * 2 + 1;
       }

       return ans;
    }
public:
    int racecar(int target) {
       for (int i = 0; i <= target; ++i) {
          dp[i] = INT_MAX;
       }
       return helper(target);
    }
};

/*
2
*/

/*
TESTS
4
8
16
32
64
*/
