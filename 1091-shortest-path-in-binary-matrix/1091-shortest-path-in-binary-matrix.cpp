class Solution {
public:
    vector<int> X{-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> Y{-1, 0, 1, -1, 1, -1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int m = grid.size(), n = grid[0].size();
        if(m == 1 and n == 1) return 1;
        queue<pair<int ,int>> q;
        q.push({0, 0}), grid[0][0] = 1;
        int len = 1;
        while(!q.empty()) {
            int t = q.size();
            ++len;
            while(t--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 8; ++i) {
                    int xx = x + X[i], yy = y + Y[i];
                    if(xx < 0 or yy < 0 or xx >= m or yy >= n or grid[xx][yy]) continue;
                    if(xx == m - 1 and yy == n - 1) return len;
                    grid[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
        return -1;
    }
};