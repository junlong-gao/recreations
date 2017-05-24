class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        deque<int> q;
        int step = 0;
       int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    r |= (1 << (i * m + j));
                }
            }
        }
        q.push_back(r);
        unordered_set<int> visited;
        vector<vector<int>> dir{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited.insert(r);
        while (q.size()) {
            int sz = q.size();
            while (sz --> 0) {
                auto top = q.front(); q.pop_front();
                if (top == 0) {
                    return step;
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        int next = top;
                        
                        for (int d = 0; d < dir.size(); ++d) {
                            int nx = i + dir[d][0];
                            int ny = j + dir[d][1];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                                continue;
                            }
                            next ^= 1 << (nx * m + ny);
                        }
                        
                        if (visited.count(next) == 0) {
                            visited.insert(next);
                            q.push_back(next);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};