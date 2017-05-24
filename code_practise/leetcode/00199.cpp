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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ret;
        deque<TreeNode *> q;
        q.push_back(root);
        while (q.size()) {
            ret.push_back(q.back()->val);
            int sz = q.size(); 
            while (sz --> 0) {
                auto top = q.front(); q.pop_front();
                if (top->left) {
                    q.push_back(top->left);
                }
                if (top->right) {
                    q.push_back(top->right);
                }
            }
        }
        