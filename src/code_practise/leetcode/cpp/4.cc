#include <gtest/gtest.h>
#include <cassert>
#include <vector>

using namespace std;

/*
 * If there are at most k element less or equal to x, then x cannot have a rank larger than k.
 1. reduce the problem by 1/4 everytime using this, easier to reduce using rank
 2. handle 0-sized and specially and handle it first, then handle r = 1
 */
class Solution {
    double findKth(int r, vector<int> &A1, int i1, int j1, vector<int> &A2, int i2, int j2) {
        if (j1 - i1 > j2 - i2) {
            return findKth(r, A2, i2, j2, A1, i1, j1);
        }

        if (j1 - i1 == 0) {
            return A2[i2+r-1];
        }

        if (r == 1) { // check this after the above one
            return min(A1[i1], A2[i2]);
        }

        int k1 = min(i1 + r/2, j1); assert(k1 - 1 >= i1);
        int k2 = min(i2 + r/2, j2); assert(k2 - 1 >= i2);
        if (A1[k1-1] <= A2[k2-1]) {
            return findKth(r - (k1 - i1), A1, k1, j1, A2, i2, j2);
        } else {
            return findKth(r - (k2 - i2), A1, i1, j1, A2, k2, j2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2) {
            return findKth(tot/2+1, nums1, 0, nums1.size(), nums2, 0, nums2.size());
        } else {
            double t1 = findKth(tot/2, nums1, 0, nums1.size(), nums2, 0, nums2.size());
            double t2 = findKth(tot/2+1, nums1, 0, nums1.size(), nums2, 0, nums2.size());

            return (t1 + t2) / 2;
        }
    }
};

TEST(Basic, BasicAssertions) {
    Solution s;
    auto l = vector<int>{1,4,6};
    auto r = vector<int>{3,5,7};

    double rst = s.findMedianSortedArrays(l, r);
    EXPECT_EQ(rst, 4.5);
}