class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        const bool canBuy = 1;
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int rem = 1; rem <= 2; ++rem) {
                dp[ind][canBuy][rem] = max(dp[ind + 1][canBuy][rem], -prices[ind] + dp[ind + 1][!canBuy][rem]);
                
                dp[ind][!canBuy][rem] = max(dp[ind + 1][!canBuy][rem], prices[ind] + dp[ind + 1][canBuy][rem - 1]);
            }
        } 
        
        return dp[0][1][2];
    }
};