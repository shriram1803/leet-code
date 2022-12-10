class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>> &dp, int r, int c, int prev, const int m, const int n) {
        if(r < 0 or c < 0 or r >= m or c >= n or matrix[r][c] <= prev) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        dp[r][c] = 0;
        int res = 1 + max({
           solve(matrix, dp, r + 1, c, matrix[r][c], m, n),
           solve(matrix, dp, r - 1, c, matrix[r][c], m, n),
           solve(matrix, dp, r, c + 1, matrix[r][c], m, n),
           solve(matrix, dp, r, c - 1, matrix[r][c], m, n) 
        });
        dp[r][c] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, solve(matrix, dp, i, j, INT_MIN, m, n));
            }
        }
        return res;
    }
};