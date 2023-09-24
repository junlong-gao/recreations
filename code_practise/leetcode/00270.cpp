/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * Assuming bst is left <= root < right.
 */
class TreeItor {
   TreeNode *root;
   /*
    * s represent a root to node path. If the path is empty, the iterator
    * is invalid and cannot be used until reseted, otherwise it points to
    * s.back().
    */
   vector<TreeNode*> s;
public:

   int kFind(double t, TreeNode* r) {
      if (r == nullptr) {
          return INT_MAX;
      }
      s.push_back(r);
      if (t == r->val) {
          return r->val;
      }
      int subtree = r->val > t ? kFind(t, r->left) : kFind(t, r->right);
      if (abs(t - r->val) < abs(t - subtree)) {
          while (s.back() != r) {s.pop_back();}
          return r->val;
      } else {
          return subtree;
      }
   }

    int Find(double t) {
        return kFind(t, root);
    }
   bool Valid() {
      return s.size() > 0;
   }
   int Val() {
      assert(Valid());
      return s.back()->val;
   }
   void Next() {
      assert(Valid());
      if (s.back()->right == nullptr) {
         TreeNode *cur = s.back();
         s.pop_back();
         while (s.size() && cur == s.back()->right) {
            cur = s.back();
            s.pop_back();
         }
      } else {
         s.push_back(s.back()->right);
         while (s.back()->left) {
            s.push_back(s.back()->left);
         }
      }
   }

   void Prev() {
      assert(Valid());
      if (s.back()->left == nullptr) {
         TreeNode *cur = s.back();
         s.pop_back();
         while (s.size() && cur == s.back()->left) {
            cur = s.back();
            s.pop_back();
         }
      } else {
         s.push_back(s.back()->left);
         while (s.back()->right) {
            s.push_back(s.back()->right);
         }
      }
   }

   TreeItor(TreeNode* _root, double val = INT_MIN):root(_root) {Find(val);}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        return TreeItor(root, target).Val();
    }
};
