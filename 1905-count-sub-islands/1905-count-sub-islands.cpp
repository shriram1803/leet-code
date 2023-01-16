class Solution {
public:
    bool dfs(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& grid1) {
        if(r < 0 or c < 0 or r >= m or c >= n or grid1[r][c] == 0) {
            return true;
        }
        if(grid1[r][c] == 1 and grid[r][c] == 0) return false;
        grid1[r][c] = 0;
        bool res = true;
        res = dfs(r + 1, c, m, n, grid, grid1) and res;
        res = dfs(r - 1, c, m, n, grid, grid1) and res;
        res = dfs(r, c + 1, m, n, grid, grid1) and res;
        res = dfs(r, c - 1, m, n, grid, grid1) and res;
        return res;            
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid2[i][j] == 1) {
                    if(dfs(i, j, m, n, grid1, grid2))
                        ++res;
                }
            }
        }
        return res;
    }
};