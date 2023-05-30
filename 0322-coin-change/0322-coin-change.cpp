class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        
        dp[0] = 0;
        
        for(int ind = 0; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                if(amt >= coins[ind])
                    dp[amt] = min(dp[amt], 1 + dp[amt - coins[ind]]);
            }
        }
        
        if(dp[amount] >= 1e9)
            return -1;
        return dp[amount];
    }
};