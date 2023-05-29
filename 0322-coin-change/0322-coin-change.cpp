class Solution {
public:
    int backtrack(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {        
        if(ind == 0) {
            if(amt % coins[0] == 0)
                return amt / coins[0];
            return 1e9;
        }
        
        if(dp[ind][amt] != -1) 
            return dp[ind][amt];
        
        int not_pick = backtrack(ind - 1, amt, coins, dp);;
        int pick = 1e9;
        if(amt >= coins[ind])
            pick = 1 + backtrack(ind, amt - coins[ind], coins, dp);
        
        return dp[ind][amt] = min(not_pick, pick);
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