class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if(i == 0 and j == 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool res = 0;
        
        if(i > 0 and s1[i - 1] == s3[i + j - 1])
            res = f(i - 1, j, s1, s2, s3, dp) | res;
        
        if(j > 0 and s2[j - 1] == s3[i + j - 1])
            res = f(i, j - 1, s1, s2, s3, dp) | res;
        
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        
        if(m + n != o)
            return 0;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return f(m, n, s1, s2, s3, dp);
    }
};