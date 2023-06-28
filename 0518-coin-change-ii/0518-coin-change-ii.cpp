class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1));
        
        for(int amt = 0; amt <= amount; ++amt) 
            if(amt % coins[0] == 0)
                dp[0][amt] = 1;
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                
                //Not pick case
                int res = dp[ind - 1][amt];

                //Pick case
                if(amt >= coins[ind])
                    res += dp[ind][amt - coins[ind]];

                dp[ind][amt] = res;
            }
        }
        
        return dp[n - 1][amount];
    }
};