class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> phi;
        int ret = 0;
        for (int i = 0; i < points.size(); ++i) {
            int dx = points[i][0] - location[0];
            int dy = points[i][1] - location[1];
            if (dx == 0 && dy == 0) {
                ret++;
            } else {
                phi.push_back(atan2(dx, dy) * 180 / M_PI);
            }
        }
        sort(phi.begin(), phi.end());
        size_t d = 0;
        deque<double> view;
        for (int i = 1; i <= phi.size() * 2; ++i) {
            if (i-1<=phi.size()-1) {
                view.push_back(phi[i - 1]);
            } else {
                view.push_back(phi[(i - 1) %phi.size()]+360);
            }
            while (view.size() > 0 && view.back() - view.front() > angle) {
                view.pop_front();
            }
            d = max(d, view.size());
        }
        return d + ret;
    }
};