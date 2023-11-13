class Solution {
    int kthSmallest(vector<int> &a, int i, int j, int k) {
        if (j == i) {
            return a[i];
        }
        int p = a[i];
        int l = i;
        for (int m = i + 1; m < j; ++m) {
            if (a[m] <= p) {
                swap(a[l+1], a[m]);
                l++;
            }
        }
        swap(a[i], a[l]);
        if (l - i + 1 == k) {
            return a[l];
        }
        
        if (l - i + 1 > k) {
            return kthSmallest(a, i, l, k);
        } else {
            return kthSmallest(a, l + 1, j, k - (l - i + 1));
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
       return kthSmallest(nums, 0, nums.size(), nums.size() - k + 1); 
    }
};