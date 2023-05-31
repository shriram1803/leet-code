class Solution {
public:
    int backtrack(int front, int back, string& s, vector<vector<int>>& dp) {
        if(front >= back) 
            return front == back;
        
        if(dp[front][back] != -1) 
            return dp[front][back];
        
        if(s[front] == s[back])
            return dp[front][back] = 2 + backtrack(front + 1, back - 1, s, dp);
        
        return dp[front][back] = max(backtrack(front + 1, back, s, dp), backtrack(front, back - 1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return backtrack(0, n - 1, s, dp);
    }
};