class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        //Perform LIS
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] += 1 + dp[i - 1][j - 1];
                else {
                    dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // backtrack the tabulation
        string res = "";
        
        while(m > 0 and n > 0) {
            if(text1[m - 1] == text2[n - 1]) {
                res += text1[--m], --n;
            } else {
                if(dp[m - 1][n] > dp[m][n - 1]) 
                    res += text1[--m];
                else
                    res += text2[--n];
            }
        }
        while(m > 0) res += text1[--m];
        while(n > 0) res += text2[--n];
        
        reverse(res.begin(), res.end());
        
        
        return res;
    }
};