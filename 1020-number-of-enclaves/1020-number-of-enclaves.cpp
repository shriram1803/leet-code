vector<int> dirs{-1, 0, 1, 0, -1};
class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if(r < 0 or c < 0 or r >= m or c >= n) {
            return -1;
        }
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int res = 1;
        for(int i = 0; i <= 3; ++i) {
            int ret = dfs(r + dirs[i], c + dirs[i + 1], m, n, grid);
            if(ret != -1 and res != -1) {
                res += ret;
            } else {
                res = -1;
            }
        }
        return res;          
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