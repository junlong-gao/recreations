class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int dfs(vector<vector<int>> &g, int x, int y) {
        int ret = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= g.size() || ny < 0 || ny >= g[0].size() ||
                g[nx][ny] == 0) {
                continue;
            }
            
            g[nx][ny] = 0;
            ret += dfs(g, nx, ny);
        }

        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    ret = max(ret, dfs(grid, i, j));
                }
            }
        }

        return ret;
    }
};
