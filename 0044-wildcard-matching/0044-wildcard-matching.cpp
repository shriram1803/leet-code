class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        
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