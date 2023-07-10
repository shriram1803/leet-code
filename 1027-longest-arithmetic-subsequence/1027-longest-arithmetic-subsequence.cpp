class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {        
        int maxi = 1, n = nums.size();
        
        vector<unordered_map<int, int>> dp(n);
        
        for(int ind = 1; ind < n; ++ind) {
            for(int k = 0; k < ind; ++k) {
                int d = nums[ind] - nums[k];
                if(dp[k].count(d)) {
                    dp[ind][d] = max(dp[ind][d], 1 + dp[k][d]);
                    maxi = max(maxi, dp[ind][d]);
                } else {
                    dp[ind][d] = 1;
                }
            }
        }
        
        return maxi + 1;
    }
};