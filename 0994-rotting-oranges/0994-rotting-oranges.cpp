class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;        
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int t = q.size();
            while(t--) {
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i <= 3; ++i) {
                    int new_x = x + dirs[i], new_y = y + dirs[i + 1];
                    if(new_x < 0 or new_y < 0 or new_x >= m or new_y >= n or grid[new_x][new_y] != 1) continue;
                    grid[new_x][new_y] = 0;
                    q.push({new_x, new_y});
                }
            }
            if(q.size()) ++res;
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1)
                    return -1;
            }
        } 
        return res;
    }
};