class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> dp(amount + 1);
        
        for(int amt = 0; amt <= amount; amt += coins[0]) 
            dp[amt] = 1;
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {

                //Pick case
                if(amt >= coins[ind])
                    dp[amt] += dp[amt - coins[ind]];
                
            }
        }
        
        return dp[amount];
    }
};