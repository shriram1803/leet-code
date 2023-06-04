class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        const bool canBuy = 1, cannotBuy = 0;
        
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            dp[ind][canBuy] = max(dp[ind + 1][canBuy], -prices[ind] +  dp[ind + 1][cannotBuy]);
        
            dp[ind][cannotBuy] = max(dp[ind + 1][cannotBuy], prices[ind] +  dp[ind + 2][canBuy]);
        }
        
        return dp[0][1];
    }
};