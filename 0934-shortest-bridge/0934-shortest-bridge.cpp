class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    void mark(vector<vector<int>>& grid, int i, int j, int n, deque<array<int, 3>>& dq) {
        if(i < 0 or j < 0 or i >= n or j >= n or grid[i][j] != 1) return;
        dq.push_back({i, j, 0});
        grid[i][j] = -1;
        for(int k = 0; k <= 3; ++k) {
            mark(grid, i + dirs[k], j + dirs[k + 1], n, dq);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        deque<array<int, 3>> dq;
        bool cont = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    mark(grid, i, j, n, dq);
                    cont = false;
                    break;
                }                
            }
            if(!cont) break;
        }
        while(!dq.empty()) {
            auto [x, y, d] = dq.front();
            dq.pop_front();
            for(int i = 0; i <= 3; ++i) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if(xx < 0  or yy < 0 or xx >= n or yy >= n or grid[xx][yy] == -1) 
                    continue;
                if(grid[xx][yy] == 1) return d;
                grid[xx][yy] = -1;
                dq.push_back({xx, yy, d + 1});
            }
        }
        return -1;
    }
};