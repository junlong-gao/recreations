#include <gtest/gtest.h>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        
        int i = 0, j = 0, m = 0;
        // s[i...j) is a range of substr of unique char, it uses mp for tracking
        // the appearance index of each char in the range.
        while (i < (int)s.size()) {
            if (mp[s[i]] >= j) {
                assert(mp[s[i]] < i);
                j = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            i++;
            
            m = max(m, i - j);
        }
        
        return m;
    }
};

TEST(Basic, BasicAssertions) {
    Solution s;

    int rst = s.lengthOfLongestSubstring("aaabc");

    EXPECT_EQ(rst, 3);
}
