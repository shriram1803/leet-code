class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n + 2, vector<int>(2));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int canBuy = 0; canBuy <= 1; ++canBuy) {
                if(canBuy) 
                    dp[ind][canBuy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                else        
                    dp[ind][canBuy] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
            }
        }
        
        return dp[0][1];
    }
};