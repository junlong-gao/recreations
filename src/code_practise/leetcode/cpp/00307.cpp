class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n, 0);
        for (int i = 0; i < nums.size(); ++i) {
            tree[i+n]=nums[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }
    
    void update(int index, int val) {
        int delta = val - tree[index + n] ;
        
        tree[index+n] += delta;
        for (int i = index + n; i > 0; i /= 2) {
            tree[i/2] += delta;
        }
    }
    
    int sumRange(int left, int right) {
        int ret = 0;
        for (int l = left + n, r = right + n + 1; l < r; l /= 2, r /= 2) {
            if (l % 2) {
                ret += tree[l];
                l++;
            }
            if (r % 2) {
                r--;
                ret += tree[r];
            }
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */