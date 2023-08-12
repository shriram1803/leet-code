class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        
        vector<int> dp(n + 1);
        
        dp[1] = 1;
        for(int i = 1; i <= obstacleGrid.size(); ++i) {
            for(int j = 1; j <= n; ++j) {
                if(obstacleGrid[i - 1][j - 1] == 1) {
                    dp[j] = 0;
                    continue;
                }
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};