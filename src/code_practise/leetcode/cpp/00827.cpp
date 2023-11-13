class Solution {
    /*
    dfs each region and map id -> size
    for every 0
       check corners to add up size.
    */
    vector<vector<int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int x, int y, vector<vector<int>> &g, int id) {
        int ret = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= g.size() || ny < 0 || ny >= g[0].size() || g[nx][ny] != 1) {
                continue;
            }
            g[nx][ny] = id;
            ret+=dfs(nx, ny, g, id);
        }
        return ret;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int id = 2;
        int best = 0;
        unordered_map<int, int> lk;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                grid[i][j]=id;
                lk[id] = dfs(i, j, grid, id);
                best = max(best, lk[id]);
                id++;
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }
                int sofar = 1; // flip 1
                unordered_set<int> used;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0 || used.count(grid[nx][ny]) == 1) {
                        continue;
                    }
                    sofar += lk[grid[nx][ny]];
                    used.insert(grid[nx][ny]);
                }
                best = max(best, sofar);
            }
        }
        
        return best;
    }
};