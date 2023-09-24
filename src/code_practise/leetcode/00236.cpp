/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool dfs(deque<TreeNode *> &path, TreeNode *r, TreeNode *q) {
        if (r == q) {
            path.push_back(r);
            return true;
        }
        if (r->left && dfs(path, r->left, q)) {
            path.push_back(r);
            return true;
        }
        if (r->right && dfs(path, r->right, q)) {
            path.push_back(r);
            return true;
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       deque<TreeNode *> l, r;
        dfs(l, root, p);
        dfs(r, root, q);
        while (r.size() > l.size()) {
            r.pop_front();
        }
        while (l.size() > r.size()) {
            l.pop_front();
        }
        for (int i = 0; i < r.size(); ++i) {
            if (l[i]->val == r[i]->val) {
                return l[i];
            }
        }
        assert(0);
    }
};