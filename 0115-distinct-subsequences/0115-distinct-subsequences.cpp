class Solution {
public:
    int backtrack(int m, int n, string& s1, string& s2, vector<vector<int>>& dp) {
        if(n < 0)
            return 1;
        if(m < 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s1[m] == s2[n])
            return dp[m][n] = backtrack(m - 1, n - 1, s1, s2, dp) + backtrack(m - 1, n, s1, s2, dp);
        
        return dp[m][n] = backtrack(m - 1, n, s1, s2, dp);
    }
    int numDistinct(string s, string t) {        
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return backtrack(m - 1, n - 1, s, t, dp);
    }
};