class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        
        dp[0] = 1;        
        for(int ind = 0; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                if(amt >= coins[ind])
                    dp[amt] += dp[amt - coins[ind]];
            }
        }
        
        return dp[amount];
    }
};