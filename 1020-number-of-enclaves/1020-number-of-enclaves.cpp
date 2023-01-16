class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if(r < 0 or c < 0 or r >= m or c >= n) {
            return -1;
        }
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int a = dfs(r + 1, c, m, n, grid);
        int b = dfs(r - 1, c, m, n, grid);
        int cx = dfs(r, c + 1, m, n, grid);
        int d = dfs(r, c - 1, m, n, grid);
        if(a < 0 or b < 0 or cx < 0 or d < 0) return -1;
        return 1 + a + b + cx + d;            
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    int ret = dfs(i, j, m, n, grid);
                    if(ret > 0)
                        res += ret;
                }
            }
        }
        return res;
    }
};