class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] == '0') 
            return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1')
                    dfs(grid, i, j), ++res;
            }
        }
        return res;
    }
};