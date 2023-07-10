class Solution {
public:
    int maxi = 0;
    int f(int r, int c, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        if(r < 0 or c < 0)
            return 0;
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int left = f(r, c - 1, matrix, dp);
        int up = f(r - 1, c, matrix, dp);
        int diag = f(r - 1, c - 1, matrix, dp);
        
        if(matrix[r][c] == '0')
            return dp[r][c] = 0;
        
        dp[r][c] = 1 + min({left, up, diag});
        
        maxi = max(maxi, dp[r][c]);
        
        return dp[r][c];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        f(m - 1, n - 1, matrix, dp);
        return maxi * maxi;
    }
};