class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) dp[i][0] = matrix[i][0], res += matrix[i][0];
        for(int j = 0; j < n; ++j) dp[0][j] = matrix[0][j], res += matrix[0][j];
        if(matrix[0][0] == 1)
            res -= 1;
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 1)
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                res += dp[i][j];
            }
        }
        return res;
    }
};