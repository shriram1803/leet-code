class Solution {
public:
    bool dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if(r < 0 or c < 0 or r >= m or c >= n) {
            return false;
        }
        if(grid[r][c] == 1) return true;
        grid[r][c] = 1;
        bool res = true;
        res = dfs(r + 1, c, m, n, grid) and res;
        res = dfs(r - 1, c, m, n, grid) and res;
        res = dfs(r, c + 1, m, n, grid) and res;
        res = dfs(r, c - 1, m, n, grid) and res;
        return res;            
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    if(dfs(i, j, m, n, grid))
                        ++res;
                }
            }
        }
        return res;
    }
};