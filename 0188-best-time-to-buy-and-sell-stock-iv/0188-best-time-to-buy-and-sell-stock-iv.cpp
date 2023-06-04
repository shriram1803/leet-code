class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2*k + 1, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int tran = 2*k - 1; tran >= 0; --tran) {
                if(tran % 2) {
                    dp[ind][tran] = max(dp[ind + 1][tran], prices[ind] + dp[ind + 1][tran + 1]);                
                } else {
                    dp[ind][tran] = max(dp[ind + 1][tran], -prices[ind] + dp[ind + 1][tran + 1]);
                }
            }
        } 
        
        return dp[0][0];
        
    }
};