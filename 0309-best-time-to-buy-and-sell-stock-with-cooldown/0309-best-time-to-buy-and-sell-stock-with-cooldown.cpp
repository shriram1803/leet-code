class Solution {
public:
    int backtrack(int ind, bool canBuy, int n, vector<int>& prices, vector<vector<int>> &dp) {
        if(ind >= n) 
            return 0;
        
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        
        if(canBuy)
            return dp[ind][1] = max(backtrack(ind + 1, canBuy, n, prices, dp), -prices[ind] +  backtrack(ind + 1, !canBuy, n, prices, dp));
        
        return dp[ind][0] = max(backtrack(ind + 1, canBuy, n, prices, dp), prices[ind] +  backtrack(ind + 2, !canBuy, n, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        
        return backtrack(0, 1, n, prices, dp);
    }
};