class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e4 + 1);
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            if(i == 0 or dp[i] > 0) {
                for(int j = i + 1; j < n and j <= i + nums[i]; ++j) {
                    dp[j] = min(dp[j], 1 + dp[i]);
                }
            }
        }
        return dp[n - 1];
    }
};