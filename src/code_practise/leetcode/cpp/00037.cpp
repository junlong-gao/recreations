class Solution {
    bool dfs(vector<vector<int>> &state, int idx, vector<vector<char>>& grid) {
        if (idx == 9 * 9) {
            return true;
        }
        
        int row = idx / 9;
        int col = idx % 9;
        if (grid[row][col] != '.') {
            return dfs(state, idx + 1, grid);
        }
        
        for (int j = 1; j <= 9; ++j) {
            if (state[0][row] & (1 << j) ||
                state[1][col] & (1 << j) ||
                state[2][row / 3 * 3 + col / 3] & (1 << j)) {
                continue;
            }
            
            state[0][row] |= (1 << j);
            state[1][col] |= (1 << j);
            state[2][row / 3 * 3 + col / 3] |= (1 << j);
            grid[row][col] = j + '0';
            if (dfs(state, idx + 1, grid)) {
                return true;
            }
            
            grid[row][col] = '.';
            state[0][row] &= ~(1 << j);
            state[1][col] &= ~(1 << j);
            state[2][row / 3 * 3 + col / 3] &= ~(1 << j);
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> state(3, vector<int>(9, 0));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    state[0][i] |= 1 << v;
                    state[1][j] |= 1 << v;
                    state[2][i / 3 * 3 + j / 3] |= 1 << v;
                }
            }
        }
        
        assert(dfs(state, 0, board));
    }
};