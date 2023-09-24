class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = INT_MAX;
        for (int i = 0; i <= min(3, (int)nums.size() - 1); ++i) {
            ret = min(ret, nums[max((int)nums.size() - 1 - (3 - i), i)] - nums[i]);
        }
        return ret;
    }
};