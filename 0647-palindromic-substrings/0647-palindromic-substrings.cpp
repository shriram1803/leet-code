class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int front = n - 1; front >= 0; --front) {
            for(int back = max(0, front - 1); back < n; ++back) {
                if(back <= front) {
                    dp[front][back] = 1;
                    continue;
                }
                if(s[front] == s[back] and dp[front + 1][back - 1] == 1)
                    dp[front][back] = 1, ans += 1;
            }
        }
    
        return ans;
    }
};