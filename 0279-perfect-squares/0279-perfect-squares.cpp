vector<int> dp(10001, -1);
class Solution {
public:
    int numSquares(int n) {
        if(n < 0)
            return 1e9;
        if(n == 0) 
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int res = 1e9;
        for(int i = 1; i*i <= n; ++i) {
            res = min(res, 1 + numSquares(n - i*i));
        }
        
        return dp[n] = res;
    }
};