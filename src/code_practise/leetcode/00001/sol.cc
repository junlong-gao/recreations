#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ret;
        for (auto i = 0; i < nums.size(); ++i) {
            if (ret.count(target - nums[i])) {
                return {ret[target - nums[i]], i};
            }
            ret[nums[i]] = i;
        }
        assert(0);
    }
};

TEST(HelloTest, BasicAssertions) {
    Solution s;
    auto in = vector<int>{2, 3};
    auto rst = s.twoSum(in, 5);
    auto expected = vector<int>{0, 1};
    EXPECT_EQ(rst, expected);
}
