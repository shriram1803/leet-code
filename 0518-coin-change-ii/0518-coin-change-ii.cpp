class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for(int i = 0; i <= amount; i += coins[0]) {
            dp[0][i] = 1;
        }
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                int not_pick = dp[ind - 1][amt];
                int pick = 0;
                if(amt >= coins[ind])
                    pick += dp[ind][amt - coins[ind]];
                dp[ind][amt] = not_pick + pick;
            }
        }
        
        return dp[n - 1][amount];
    }
};