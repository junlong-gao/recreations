// key idea: for char beta, if it is less than constructed string end alpha, and there are still alpha left after beta,
// we should just remove alpha for beta
class Solution {
public:
    string removeDuplicateLetters(string s) {
         string ret;
        unordered_set<char> cur;
        unordered_map<char, int> refcount;
        for (auto c : s) {
            refcount[c]++;
        }
        for (auto c : s) {
            if (cur.count(c)) {
                refcount[c]--;
                continue;
            }
            while (ret.size() && ret.back() > c && refcount[ret.back()] > 0) {
                cur.erase(ret.back());
                ret.pop_back();
            }
            ret.push_back(c);
            refcount[c]--;
            cur.insert(c);
        }
        return ret;
    }
};
