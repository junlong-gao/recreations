class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                }
            } else {
                if (nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i+1]);
                }
            }
        }
    }
};