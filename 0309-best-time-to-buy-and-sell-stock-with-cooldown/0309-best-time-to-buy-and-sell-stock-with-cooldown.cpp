class Solution {
public:
    int f(int ind, bool canBuy, const int n, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind >= n)
            return 0;
        
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        
        if(canBuy) {
            return dp[ind][canBuy] = max(-prices[ind] + f(ind + 1, 0, n, prices, dp), f(ind + 1, 1, n, prices, dp));
        }
        
        return dp[ind][canBuy] = max(prices[ind] + f(ind + 2, 1, n, prices, dp), f(ind + 1, 0, n, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(0, 1, n, prices, dp);
    }
};