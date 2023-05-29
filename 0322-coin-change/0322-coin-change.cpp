class Solution {
public:
    int backtrack(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {        
        if(amt == 0)
            return 0;
        if(ind == 0 and amt < coins[0]) 
            return 1e9;
        
        if(dp[ind][amt] != -1) 
            return dp[ind][amt];
        
        int not_pick = 1e9;
        int pick_stay = 1e9;
        int pick_move = 1e9;
        if(amt >= coins[ind]) {
            pick_stay = backtrack(ind, amt - coins[ind], coins, dp);
            if(ind > 0)
                pick_move = backtrack(ind - 1, amt - coins[ind], coins, dp);
        }
        if(ind > 0)
            not_pick = backtrack(ind - 1, amt, coins, dp);
        
        return dp[ind][amt] = min(not_pick, 1 + min(pick_stay, pick_move));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = backtrack(n - 1, amount, coins, dp);
        if(res == 1e9)
            return -1;
        return res;
    }
};