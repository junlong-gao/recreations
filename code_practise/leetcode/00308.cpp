class NumMatrix {
    vector<vector<int>> tree;
    int n, m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        tree.resize(n * 2, vector<int>(m *2, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tree[i+n][j+m] = matrix[i][j];
            }
            for (int j = m - 1; j > 0; --j) {
                tree[i+n][j] = tree[i+n][j*2] + tree[i+n][j*2+1];
            }
        }
        
        for (int i = n-1; i > 0; --i) {
            for (int j = 0; j < 2*m; ++j) {
                tree[i][j] = tree[i*2][j] + tree[i*2+1][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - tree[row + n][col + m];
        for (int i = (row + n); i > 0; i /= 2) {
            tree[i][col + m] += delta;
            for (int j = (col + m); j > 0; j /= 2) {
                tree[i][j/2] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int lx = row1 + n, rx = row2+1 + n; lx < rx; lx /= 2, rx /= 2) {
            if (lx % 2) {
                for (int ly = col1 + m, ry = col2+1+m; ly < ry; ly /= 2, ry /= 2) {
                    if (ly % 2) {
                        ret += tree[lx][ly];
                        ly++;
                    }
                    if (ry % 2) {
                        ry--;
                        ret += tree[lx][ry];
                    }
                }
                lx++;
            }
            if (rx % 2) {
                rx--;
                for (int ly = col1 + m, ry = col2+1+m; ly < ry; ly /= 2, ry /= 2) {
                    if (ly % 2) {
                        ret += tree[rx][ly];
                        ly++;
                    }
                    if (ry % 2) {
                        ry--;
                        ret += tree[rx][ry];
                    }
                }
            }
        }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */