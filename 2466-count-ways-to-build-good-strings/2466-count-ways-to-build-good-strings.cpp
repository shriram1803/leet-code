class Solution {
public:
    const int mod = (int)(1e9 + 7);
    int f(int curr, int zero, int one, int low, int high, vector<int>& dp) {
        if(curr > high)
            return 0;
        
        if(dp[curr] != -1)
            return dp[curr];
        
        int res = 0;
        if(curr >= low)
            res += 1;
        
        return dp[curr] = (res + f(curr + one, zero, one, low, high, dp) % mod + f(curr + zero, zero, one, low, high, dp) % mod) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, -1);
        
        return f(0, zero, one, low, high, dp);
    }
};