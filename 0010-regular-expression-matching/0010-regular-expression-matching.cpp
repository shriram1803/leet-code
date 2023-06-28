class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        
        if(i == 0 and j == 0) {
            return 1;
        }
        
        if(i == 0) {
            while(j > 0) {
                if(p[j - 1] != '*')
                    return 0;
                j -= 2;
            }
            return 1;
        }
        
        if(j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j - 1] == '.' or s[i - 1] == p[j - 1]) 
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        
        if(p[j - 1] == '*') {
            if(s[i - 1] == p[j - 2] or p[j - 2] == '.')
                return dp[i][j] = f(i - 1, j - 1, s, p, dp) | f(i - 1, j, s, p, dp) | f(i, j - 2, s, p, dp);
            else
                return dp[i][j] = f(i, j - 2, s, p, dp);
        }
        
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return f(m, n, s, p, dp);
    }
};