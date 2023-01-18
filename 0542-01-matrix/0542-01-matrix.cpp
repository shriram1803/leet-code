class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) 
                    q.push({i, j}), vis[i][j] = 1;                    
            }
        }
        if(q.size() == m * n) return mat;
        int level = 0;
        while(!q.empty()) {
            int t = q.size();
            while(t--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                mat[x][y] = level;
                for(int i = 0; i <= 3; ++i) {
                    int xx = x + dirs[i], yy = y + dirs[i + 1];                    
                    if(xx < 0 or yy < 0 or xx >= m or yy >= n or vis[xx][yy]) 
                        continue;
                    vis[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
            ++level;        
        }
        return mat;
    }
};