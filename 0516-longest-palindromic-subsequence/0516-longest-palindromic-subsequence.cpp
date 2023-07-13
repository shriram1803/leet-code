class Solution {
public:
    int f(int front, int back, string& s, vector<vector<int>>& dp) {
        if(front > back)
            return 0;
        if(front == back)
            return 1;
        
        if(dp[front][back] != -1)
            return dp[front][back];
        
        if(s[front] == s[back])
            return dp[front][back] = 2 + f(front + 1, back - 1, s, dp);
        
        return dp[front][back] = max(f(front + 1, back, s, dp), f(front, back - 1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, s, dp);
    }
};