class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            dp[ind][0] = max(dp[ind + 1][0], prices[ind] + dp[ind + 1][1]);
            dp[ind][1] = max(dp[ind + 1][1], -prices[ind] + dp[ind + 1][0]);
        }
        
        return dp[0][1];
    }
};