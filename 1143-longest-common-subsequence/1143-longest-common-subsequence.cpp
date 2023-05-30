class Solution {
public:
    int backtrack(int m, int n, string& s1, string& s2, vector<vector<int>>& dp) {
        if(m < 0 or n < 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s1[m] == s2[n])
            return 1 + backtrack(m - 1, n - 1, s1, s2, dp);
        
        return dp[m][n] = max(backtrack(m - 1, n, s1, s2, dp), backtrack(m, n - 1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return backtrack(m - 1, n - 1, text1, text2, dp);
    }
};