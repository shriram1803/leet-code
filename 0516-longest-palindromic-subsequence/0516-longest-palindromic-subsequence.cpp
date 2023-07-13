class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        
        for(int front = n - 1; front >= 0; --front) {
            for(int back = front + 1; back < n; ++back) {
                if(s[front] == s[back])
                    dp[front][back] = 2 + dp[front + 1][back - 1];
                else
                    dp[front][back] = max(dp[front + 1][back], dp[front][back - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};