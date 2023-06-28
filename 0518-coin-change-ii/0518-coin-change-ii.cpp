class Solution {
public:
    int f(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if(ind == 0)
            return amt % coins[0] == 0;
        
        if(dp[ind][amt] != -1)
            return dp[ind][amt];
        
        //Not pick case
        int res = f(ind - 1, amt, coins, dp);
        
        //Pick case
        if(amt >= coins[ind])
            res += f(ind, amt - coins[ind], coins, dp);
        
        return dp[ind][amt] = res;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return f(n - 1, amount, coins, dp);
    }
};