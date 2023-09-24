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
    // 0 -> covered, no camera
    // 1 -> not covered, no camera
    // 2 -> has camera
    // don't place camera on the leaf unless it is also a root (no parent)
    int dfs(TreeNode *root, TreeNode *parent, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        int ls = dfs(root->left, root, ans);
        int rs = dfs(root->right, root, ans);
        if (ls == 2 || rs == 2) {
            ans++;
            return 1;
        }
        if (ls == 1 || rs == 1) {
            return 0;
        }
        if (parent == nullptr) {
            ans++;
        }
        return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
       int ret = 0;
        dfs(root, nullptr, ret);
        return ret;
    }
};