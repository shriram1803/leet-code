class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> dp(5, 0);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int tran = 0; tran <= 3; ++tran) {
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