class Solution {
public:
    int backtrack(int ind, int n, bool canBuy, int rem, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(ind == n)
            return 0;
        if(rem == 0)
            return 0;
        
        if(dp[ind][canBuy][rem] != -1)
            return dp[ind][canBuy][rem];
        
        if(canBuy) {
            return dp[ind][canBuy][rem] = max(backtrack(ind + 1, n, canBuy, rem, prices, dp), -prices[ind] + backtrack(ind + 1, n, !canBuy, rem, prices, dp));
        }
        
        return dp[ind][canBuy][rem] = max(backtrack(ind + 1, n, canBuy, rem, prices, dp), prices[ind] + backtrack(ind + 1, n, !canBuy, rem - 1, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return backtrack(0, n, 1, 2, prices, dp);
    }
};