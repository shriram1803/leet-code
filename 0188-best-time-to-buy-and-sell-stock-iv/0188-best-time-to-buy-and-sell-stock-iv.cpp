class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> dp(2*k + 1, 0);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int tran = 0; tran < 2*k; ++tran) {
                if(tran % 2) {
                    dp[tran] = max(dp[tran], prices[ind] + dp[tran + 1]);       
                } else {
                    dp[tran] = max(dp[tran], -prices[ind] + dp[tran + 1]);
                }
            }
        } 
        
        return dp[0];
        
    }
};