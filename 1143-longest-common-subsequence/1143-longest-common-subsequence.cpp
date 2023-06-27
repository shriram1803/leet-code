class Solution {
public:
    int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i == 0 or j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i - 1] == text2[j - 1])
            return 1 + f(i - 1, j - 1, text1, text2, dp);
        
        return dp[i][j] = max(
            f(i - 1, j, text1, text2, dp), 
            f(i, j - 1, text1, text2, dp)
        );
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return f(m, n, text1, text2, dp);
    }
};