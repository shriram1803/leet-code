class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int a, b;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!i and !j)
                    continue;
                a = INT_MAX;
                b = INT_MAX;
                if(i > 0){
                    a = grid[i - 1][j];
                }
                if(j > 0){
                    b = grid[i][j - 1];
                }
                grid[i][j] += min(a, b);
            }
        }
        return grid[m - 1][n - 1];        
    }
};