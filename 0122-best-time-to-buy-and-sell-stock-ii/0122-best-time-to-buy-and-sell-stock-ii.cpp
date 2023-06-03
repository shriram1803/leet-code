class Solution {
public:
    int backtrack(int ind, int n, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == n)
            return 0;
        
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        
        if(canBuy) {
            return dp[ind][canBuy] = max(backtrack(ind + 1, n, canBuy, prices, dp), -prices[ind] + backtrack(ind + 1, n, !canBuy, prices, dp));
        }
        
        return dp[ind][canBuy] = max(backtrack(ind + 1, n, canBuy, prices, dp), prices[ind] + backtrack(ind + 1, n, !canBuy, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return backtrack(0, prices.size(), 1, prices, dp);
    }
};