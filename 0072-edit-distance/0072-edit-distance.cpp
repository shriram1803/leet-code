class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        
        for(int i = 0; i <= s1; ++i) dp[i][0] = i;
        for(int i = 0; i <= s2; ++i) dp[0][i] = i;
        
        for(int m = 1; m <= s1; ++m) {
            for(int n = 1; n <= s2; ++n) {
                if(word1[m - 1] == word2[n - 1]) {
                    dp[m][n] = dp[m - 1][n - 1];
                } else {
                    dp[m][n] = 1 + min({
                        dp[m - 1][n], dp[m][n - 1], dp[m - 1][n - 1]
                    });
                }
            }
        }
        
        
        return dp[s1][s2];
    }
};