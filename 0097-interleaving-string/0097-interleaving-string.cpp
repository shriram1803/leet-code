class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        
        if(m + n != o)
            return 0;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                
                if(i > 0 and s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j] | dp[i][j];

                if(j > 0 and s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j - 1] | dp[i][j];
                
            }
        }
        
        return dp[m][n];
    }
};