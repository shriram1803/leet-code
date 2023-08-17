class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        deque<array<int, 3>> dq;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0)
                    dq.push_back({i, j, 0});
                else
                    mat[i][j] = 1e9;
            }
        }
        
        vector<int> dirs{-1, 0, 1, 0, -1};
        while(!dq.empty()) {
            auto [x, y, dst] = dq.front();
            dq.pop_front();
            
            for(int i = 0; i <= 3; ++i) {
                int cur_x = x + dirs[i], cur_y = y + dirs[i + 1];
                if(cur_x < 0 or cur_y < 0 or cur_x >= m or cur_y >= n or mat[cur_x][cur_y] <= dst + 1)
                    continue;
                mat[cur_x][cur_y] = dst + 1;
                dq.push_back({cur_x, cur_y, dst + 1});
            }
            
        }
        
        return mat;
    }
};