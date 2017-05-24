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
        TreeNode *r;
        int x;
    };
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        map<int, vector<int>> coor;
        deque<ent_t> q;
        q.push_back(ent_t{root, 0});
        while (q.size()) {
            int sz = q.size();
            while (sz --> 0) {
                auto top = q.front(); q.pop_front();
                coor[top.x].push_back(top.r->val);
                if (top.r->left) {
                    q.push_back(ent_t{top.r->left, top.x - 1});
                }
                if (top.r->right) {
                    q.push_back(ent_t{top.r->right, top.x + 1});
                }
            }
        }
        
        vector<vector<int>> ret;
        for (auto  &pr : coor) {
            ret.emplace_back(move(pr.second));
        }
        return ret;
    }
};