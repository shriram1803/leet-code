class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    void pacfill(vector<vector<int>>& heights, vector<vector<int>>& v) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) q.push({0, i}), v[0][i] = 1;
        for(int i = 0; i < m; ++i) q.push({i, 0}), v[i][0] = 1;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i <= 3; ++i) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if(xx < 0 or yy < 0 or xx >= m or yy >= n or v[xx][yy] or heights[xx][yy] < heights[x][y]) 
                    continue;
                v[xx][yy] = 1;
                q.push({xx, yy});                
            }
        }
    }
    void atlfill(vector<vector<int>>& heights, vector<vector<int>>& v) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) q.push({m - 1, i}), v[m - 1][i] = 1;
        for(int i = 0; i < m; ++i) q.push({i, n - 1}), v[i][n - 1] = 1;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i <= 3; ++i) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if(xx < 0 or yy < 0 or xx >= m or yy >= n or v[xx][yy] or heights[xx][yy] < heights[x][y]) 
                    continue;
                v[xx][yy] = 1;
                q.push({xx, yy});                
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0)), res;
        pacfill(heights, pac), atlfill(heights, atl);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pac[i][j] == 1 and atl[i][j] == 1)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};