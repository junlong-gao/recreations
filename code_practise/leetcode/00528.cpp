class Solution {
    vector<int> acc;
    int tot;
public:
    Solution(vector<int>& w) {
        tot = 0;
        acc.push_back(0);
        for (auto v : w) {
            acc.push_back(acc.back() + v);
            tot += v;
        }
    }
    
    int pickIndex() {
        int draw = rand() % tot;
        auto it = upper_bound(acc.begin(), acc.end(), draw);
        return it - acc.begin() - 1;
    }
};