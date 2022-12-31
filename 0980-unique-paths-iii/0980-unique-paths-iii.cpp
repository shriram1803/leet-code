class Solution {
public:
    vector<int> dirs{0, 1, 0, -1, 0};
    int dfs(vector<vector<int>>& g, int cnt, int total, int r, int c, int m, int n) 
    {
        if(r < 0 or c < 0 or r >= m or c >= n or g[r][c] == -1) return 0;
        if(g[r][c] == 2) {
            return cnt == total ? 1 : 0;
        }
        g[r][c] = -1;
        int res = 0;
        for(int i = 0; i < 4; ++i) {
            int next_r = dirs[i] + r, next_c = dirs[i + 1] + c;
            res += dfs(g, cnt + 1, total, next_r, next_c, m, n);
        }
        g[r][c] = 0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int obs_cnt = 0;
        pair<int, int> start = {-1, -1};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == -1) {
                    ++obs_cnt;
                } else if(grid[i][j] == 1) {
                    start.first = i;
                    start.second = j;
                }
            }
        }

        return dfs(grid, 1, m * n - obs_cnt, start.first, start.second, m, n);
    }
};