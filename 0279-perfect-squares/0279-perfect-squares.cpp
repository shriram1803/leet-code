class Solution {
public:
    void fillSqrts(vector<int>& v, int n) {
        int i = 1;
        while(i*i <= n) {
            v.emplace_back(i*i);
            ++i;
        }
    }
    int numSquares(int n) {
        vector<int> v;
        fillSqrts(v, n);
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 1, dp[0] = 0;
        for(int i = 2; i <= n; ++i) {
            for(int val : v) {
                if(val <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - val]);
                }
            }
        }
        return dp[n];
    }
};