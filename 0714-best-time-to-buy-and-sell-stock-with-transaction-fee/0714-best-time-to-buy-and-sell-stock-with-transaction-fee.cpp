class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int canBuy = 0; canBuy <= 1; ++canBuy) {
                if(canBuy) {
                    int not_pick = dp[ind + 1][1];
                    int pick = -prices[ind] - fee + dp[ind + 1][0];
                    dp[ind][canBuy] = max(not_pick, pick);
                } else {
                    int not_pick = dp[ind + 1][0];
                    int pick = prices[ind] + dp[ind + 1][1];
                    dp[ind][canBuy] = max(not_pick, pick);
                }                
            }
        }
        
        return dp[0][1];
    }
};