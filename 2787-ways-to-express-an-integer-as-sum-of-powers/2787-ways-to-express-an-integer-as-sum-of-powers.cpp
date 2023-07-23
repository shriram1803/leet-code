class Solution {
public:
    const int mod = (int)(1e9 + 7);
    
    int Root(int num, int x) {
        return ceil(pow(num, 1/(double)x));
    }
    
    int f(int n, int val, int x, vector<vector<int>>& dp) {
        if(n == 0)
            return 1;
        if(val == 0)
            return 0;
        
        if(dp[n][val] != -1)
            return dp[n][val];
        
        int not_pick = f(n, val - 1, x, dp);
        int pick = 0;
        if(pow(val, x) <= n) 
            pick = f(n - pow(val, x), val - 1, x, dp);
        
        return dp[n][val] = (not_pick % mod + pick % mod) % mod;
    }
    
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(1 + Root(n, x), -1));
        
        return f(n, Root(n, x), x, dp);   
    }
};