class Solution {
public:
    vector<vector<int>> moves{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {1, 2}};
    double dfs(int r, int c, int k, const int n,vector<vector<vector<double>>>& dp) {
        if(r < 0 or c < 0 or r >= n or c >= n)
            return 0;
        
        if(dp[r][c][k] != -1)
            return dp[r][c][k];
        
        if(k == 0)
            return 1;
        
        double ans = 0;
        for(auto& move : moves) {
            ans += dfs(r + move[0], c + move[1], k - 1, n, dp);
        }
        
        return dp[r][c][k] = ans / 8;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return dfs(row, column, k, n, dp);
    }
};