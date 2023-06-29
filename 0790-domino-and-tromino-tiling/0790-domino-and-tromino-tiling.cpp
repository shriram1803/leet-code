class Solution {
public:
    const int mod = (int)(1e9 + 7);
    long long f(int up, int down, vector<vector<int>>& dp) {
        if(up == 0 and down == 0)
            return 1;
        if(up <= 0 or down <= 0)
            return 0;
        
        if(dp[up][down] != -1)
            return dp[up][down];
        
        long long res = 0;
        
        if(up == down - 1)
            res += (f(up, down - 2, dp) % mod + f(up - 1, down - 2, dp) % mod) % mod;
        else if(up - 1 == down)
            res += (f(up - 2, down, dp) % mod + f(up - 2, down - 1, dp) % mod) % mod;
        else
            res += (f(up - 1, down - 1, dp) % mod + f(up - 2, down - 2, dp) % mod + 
                   f(up - 2, down - 1, dp) % mod + f(up - 1, down - 2, dp) % mod) % mod;
        
        return dp[up][down] = res % mod;
    }
    int numTilings(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return f(n, n, dp); 
    }
};