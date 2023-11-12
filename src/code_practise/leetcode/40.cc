#include <gtest/gtest.h>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    void helper(int i, int cur, const vector<int> &vs, vector<int> &bag, vector<vector<int>> &sol) {
        if (i == (int)vs.size()) {
            if (cur == 0 && !bag.empty()) {
                sol.push_back(bag);
            }
            return;
        } else {
            int v = vs[i];
            if (cur >= v) {
                bag.push_back(v);
                helper(i+1,cur-v,vs,bag,sol);
                bag.pop_back();
            }

            if (bag.empty() || bag.back() != v) {
                helper(i+1,cur,vs,bag,sol);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> bag;
        helper(0,target,candidates,bag,ret);
        return ret;
    }
};

/*
bazel test --cxxopt=-std=c++14 --test_output=all //src/code_practise/leetcode/00001:test
*/

TEST(HelloTest, BasicAssertions) {
    Solution s;
    auto vs = vector<int>{1, 1};
    auto rst = s.combinationSum2(vs, 2);
    auto expected = vector<vector<int>>{vector<int>{1, 1}};
    EXPECT_EQ(rst, expected);
}
