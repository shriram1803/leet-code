vector<int> dirs{-1, 0, 1, 0, -1};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
             for(int j = 0; j < n; ++j) {
                 if(grid[i][j] == 1) {
                     for(int k = 0; k <= 3; ++k) {
                         q.push({i + dirs[k], j + dirs[k + 1]});
                     }
                 }
             }
        }
        while(!q.empty()) {
            ++res;
            int t = q.size();
            while(t--) {
                auto [x, y] = q.front(); q.pop();
                if(x >= 0 and y >= 0 and x < n and y < n and grid[x][y] == 0) {
                    grid[x][y] = res;
                    for(int i = 0; i <= 3; ++i) {
                        q.push({x + dirs[i], y + dirs[i + 1]});
                    }
                }     
            }
            
        }
        return res == 1 ? -1 : res - 1;
    }
};