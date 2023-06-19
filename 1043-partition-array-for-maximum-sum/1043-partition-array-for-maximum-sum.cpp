class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            int maxi = -1;        
            for(int j = ind; j < min(ind + k, n); ++j) {
                maxi = max(maxi, arr[j]);
                dp[ind] = max(dp[ind], maxi*(j - ind + 1) + dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};