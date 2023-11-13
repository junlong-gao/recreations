class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> s, process = nums, ret;
        for (int i = 0; i < nums.size(); ++i) {
            process.push_back(nums[i]);
        }
        for (int i = process.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.back() <= process[i]) {
                s.pop_back();
            }
            if (i < nums.size()) {
                if (!s.empty()) {
                    ret.push_back(s.back());
                } else {
                    ret.push_back(-1);
                }
            }
            s.push_back(process[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
