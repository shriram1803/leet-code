class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] == 0) 
            return 0;
        int local_res = grid[r][c];
        grid[r][c] = 0;
        for(int i = 0; i <= 3; ++i) {
            local_res += dfs(grid, r + dirs[i], c + dirs[i + 1]);
        }
        return local_res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] != 0) 
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};