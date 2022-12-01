class Solution {
public:
    int solve(vector<int>& nums, int ind, int prev, int picks, const int n, vector<vector<int>>& dp) {
        if(ind == n) {
            return 0;
        }
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1]; 
        int val = solve(nums, ind + 1, prev, picks, n, dp);
        if(prev == -1 or nums[ind] > nums[prev])
            val = max(val, 1 + solve(nums, ind + 1, ind, picks + 1, n, dp));
        dp[ind][prev + 1] = val;
        return val;
    }
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int val = solve(nums, 0, -1, 0, n, dp);
        return val;
    }
};