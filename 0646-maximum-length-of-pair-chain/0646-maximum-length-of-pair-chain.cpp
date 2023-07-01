class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        vector<int> dp(n, 1);
        sort(pairs.begin(), pairs.end());
        
        //Pure LIS Pattern
        for(int ind = 1; ind < n; ++ind) {
            for(int k = ind - 1; k >= 0; --k) {
                if(pairs[ind][0] > pairs[k][1]) {
                    dp[ind] = max(dp[ind], 1 + dp[k]);
                    break;
                }
            }
        }
        
        return dp[n - 1];
    }
};