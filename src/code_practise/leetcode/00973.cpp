class Solution {
    using ll = unsigned long long;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](ll dx, ll dy) {
            return dx * dx + dy * dy;
        };
        auto cmp = [&points, &dist](int l, int r) {
            return dist(points[l][0], points[l][1]) > dist(points[r][0], points[r][1]);
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < points.size(); ++i) {
            q.push(i);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < k; ++i) {
            auto t = q.top();
            q.pop();
            ret.push_back({points[t][0], points[t][1]});
        }
        return ret;
    }
};