class Solution {
    struct ent_t {
      int x; int y;  
    };
    vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void bfs(vector<vector<int>> &h, deque<ent_t> &q, vector<vector<int>> &c) {
        vector<vector<bool>> visited(c.size(), vector<bool>(c[0].size(), false));
        for (auto p : q) {
            visited[p.x][p.y] = 1;
        }
        while (q.size()) {
            int sz = q.size();
            while (sz --> 0) {
                auto top = q.front(); q.pop_front();
                for (auto d : dir) {
                    int nx = top.x + d[0];
                    int ny = top.y + d[1];
                    if (nx < 0 || nx >= h.size() || ny < 0 || ny >= h[0].size() ||
                        visited[nx][ny] || h[nx][ny] < h[top.x][top.y]) {
                        continue;
                    }
                    visited[nx][ny] = 1;
                    c[nx][ny]++;
                    q.push_back(ent_t{nx, ny});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0) {
            return {};
        }
        vector<vector<int>> c(heights.size(), vector<int>(heights[0].size(), 0));
        deque<ent_t> q;
        
        for (int i = 0; i < heights.size(); ++i) {
            q.push_back(ent_t{i, 0});
            c[i][0]++;
        }
        for (int j = 1; j < heights[0].size(); ++j) {
            q.push_back(ent_t{0, j});
            c[0][j]++;
        }
        bfs(heights, q, c);
        
        for (int i = 0; i < heights.size(); ++i) {
            q.push_back(ent_t{i, (int)heights[i].size() - 1});
            c[i][(int)heights[i].size() - 1]++;
        }
        for (int j = 0; j < heights[0].size() - 1; ++j) {
            q.push_back(ent_t{(int)heights.size() - 1, j});
            c[(int)heights.size() - 1][j]++;
        }
        bfs(heights, q, c);
        
        vector<vector<int>> ret;
        for (int i = 0; i < c.size(); ++i) {
            for (int j = 0; j < c[i].size(); ++j) {
                if (c[i][j]== 2) {
                    ret.push_back(vector<int>{i, j});
                }
            }
        }
        
        return ret;
    }
};