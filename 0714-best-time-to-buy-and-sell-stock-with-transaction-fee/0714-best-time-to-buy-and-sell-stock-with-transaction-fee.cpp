class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        const bool canBuy = 1, cannotBuy = 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            dp[ind][canBuy] = max(dp[ind + 1][canBuy], -prices[ind] +  dp[ind + 1][cannotBuy]);
            
            // Similar to Stock II - Just subtracted the transaction fee 
            dp[ind][cannotBuy] = max(dp[ind + 1][cannotBuy], prices[ind] - fee +  dp[ind + 1][canBuy]);
        }
        
        return dp[0][1];
    }
};