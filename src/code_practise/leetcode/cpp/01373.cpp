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
class Solution {
    struct ent_t {
        int sum;
        bool valid;
        int l, r;
    };
    
    int best;
    ent_t search(TreeNode* root) {
        if (root == nullptr) {
            return ent_t {
                0, true, INT_MAX, INT_MIN
            };
        }
        auto l = search(root->left);
        auto r = search(root->right);
        if (l.valid && r.valid && l.r < root->val && r.l > root->val) {
            ent_t ret {
                root->val + l.sum + r.sum,
                true,
                min(root->val, l.l), max(root->val, r.r) // need to handle this better?
            };
            best = max(best, ret.sum);
            return ret;
        } else {
            return ent_t {
                0, false, 0, 0
            };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        best = 0;
        search(root);
        return best;
    }
};
