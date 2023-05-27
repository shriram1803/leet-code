class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[101][101] = { 0 };
        dp[1][1] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) 
                if(grid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};