class Solution {
public:
    int f(int ind, const int n, const int k, vector<int>& arr, vector<int>& dp) {
        if(ind >= n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int res = -1, maxi = -1;
        
        for(int j = ind; j < n and j < ind + k; ++j) {
            maxi = max(maxi, arr[j]);
            res = max(res, maxi*(j - ind + 1) + f(j + 1, n, k, arr, dp));
        }
        
        return dp[ind] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, k, arr, dp);
    }
};