class Solution {
public:
    int backtrack(int m, int n, string& word1, string& word2, vector<vector<int>>& dp) {
        
        if(m == 0) return n;
        if(n == 0) return m;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(word1[m - 1] == word2[n - 1])
            return dp[m][n] = backtrack(m - 1, n - 1, word1, word2, dp);
        
        return dp[m][n] = 1 + min({
            backtrack(m - 1, n, word1, word2, dp),
            backtrack(m, n - 1, word1, word2, dp),
            backtrack(m - 1, n - 1, word1, word2, dp)
        });
    }
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));
        
        return backtrack(s1, s2, word1, word2, dp);
    }
};