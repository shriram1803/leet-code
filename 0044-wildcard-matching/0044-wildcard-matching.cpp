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
            return dp[m][n] = backtrack(m - 1, n, s, p, dp) | backtrack(m, n - 1, s, p, dp);
        
        return dp[m][n] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        if(p.size() == 0)
            p += "!";
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return backtrack(m, n, s, p, dp);
    }
};