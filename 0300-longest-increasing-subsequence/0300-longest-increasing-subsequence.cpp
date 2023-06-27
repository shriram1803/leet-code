class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0)
            return nums[ind] < nums[prev];
        
        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int not_pick = f(ind - 1, prev, nums, dp);
        int pick = -1e9;
        if(prev == -1 or nums[ind] < nums[prev])
            pick = 1 + f(ind - 1, ind, nums, dp);
        
        return dp[ind][prev] = max(not_pick, pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.emplace_back(1e9);
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, nums, dp);
    }
};