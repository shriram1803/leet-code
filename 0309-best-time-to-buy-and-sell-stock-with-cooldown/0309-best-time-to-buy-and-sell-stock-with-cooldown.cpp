class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(3, vector<int>(2));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int canBuy = 0; canBuy <= 1; ++canBuy) {
                if(canBuy) 
                    dp[0][canBuy] = max(-prices[ind] + dp[1][0], dp[1][1]);
                else        
                    dp[0][canBuy] = max(prices[ind] + dp[2][1], dp[1][0]);
            }
            dp[2] = dp[1], dp[1] = dp[0];
        }
        
        return dp[0][1];
    }
};