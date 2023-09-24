/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Need to define proper ordering when diffs are equal
*/
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        auto cmp = [target](const int l, const int r) {
            double dl = abs(double(l) - target);
            double dr = abs(double(r) - target);
            if (dl != dr) {
                return dl < dr;
            }
            return l < r;
        };
        set<int, decltype(cmp)> bag(cmp);
        
        vector<TreeNode *> s;
        TreeNode *cur = root;
        while (true) {
            while (cur) {
                s.push_back(cur);
                cur = cur->left;
            }
            
            if (s.empty()) {
                break;
            }
            
            TreeNode *visiting = s.back(); s.pop_back();
            bag.insert(visiting->val);
            
            if (bag.size() > k) {
                bag.erase(prev(bag.end()));
            }
            
            cur = visiting->right;
        }
        
        return {bag.begin(), bag.end()};
    }
};