class Solution {
public:
    void fillPalDP(string& s, vector<vector<int>>& dp) {
        
        int n = dp.size();
        
        for(int front = n - 1; front >= 0; --front) {
            for(int back = max(0, front - 1); back < n; ++back) {
                if(back <= front) {
                    dp[front][back] = 1;
                    continue;
                }
                if(s[front] == s[back]) {
                    dp[front][back] = dp[front + 1][back - 1];   
                }                    
            }
        }
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        vector<vector<int>> palDP(n, vector<int>(n, 0));
        
        fillPalDP(s, palDP);
        
        dp[n] = 0;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int k = ind; k < n; ++k) {
                if(palDP[ind][k])
                    dp[ind] = min(dp[ind], 1 + dp[k + 1]);
            }
        }
        
        return dp[0] - 1;
    }
};