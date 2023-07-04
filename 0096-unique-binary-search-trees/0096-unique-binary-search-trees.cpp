vector<int> dp(20, -1);
class Solution {
public:
    int f(int n) {
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res += f(i) * f(n - i - 1);
        }
            
        return dp[n] = res;
    }
    int numTrees(int n) {
        return f(n);
    }
};