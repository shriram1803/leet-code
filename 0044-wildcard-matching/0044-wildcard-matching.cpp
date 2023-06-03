class Solution {
public:
    bool backtrack(int m, int n, string& s, string& p, vector<vector<int>>& dp) {
        if(m == 0 and n == 0)
            return 1;
        
        if(m > 0 and n == 0)
            return 0;
        
        if(m == 0 and n > 0) {
            for(int j = n - 1; j >= 0; --j)
                if(p[j] != '*')
                    return 0;
            return 1;
        }
        
        if(dp[m][n] != -1) 
            return dp[m][n];
            
        if(s[m - 1] == p[n - 1] or p[n - 1] == '?')
            return dp[m][n] = backtrack(m - 1, n - 1, s, p, dp);
        
        if(p[n - 1] == '*')
            return dp[m][n] = backtrack(m - 1, n, s, p, dp) || backtrack(m, n - 1, s, p, dp);
        
        return dp[m][n] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            if(p[i - 1] != '*')
                break;
            dp[0][i] = 1;
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {                    
                if(s[i - 1] == p[j - 1] or p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
        }
        
        return dp[m][n];
    }
};