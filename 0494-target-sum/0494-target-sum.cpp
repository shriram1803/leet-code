class Solution {
public:
    int backtrack(int ind, int targ, vector<int>& nums, vector<vector<int>>& dp) {
        
        if(ind == 0) {
            return (targ == 0) + (targ == nums[0]);
        }
        
        if(dp[ind][targ] != -1)
            return dp[ind][targ];
        
        int not_pick = backtrack(ind - 1, targ, nums, dp);
        int pick = 0;
        if(targ >= nums[ind]) 
            pick += backtrack(ind - 1, targ - nums[ind], nums, dp);
        
        return dp[ind][targ] = (pick + not_pick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        
        if(total < target or (total - target) % 2 == 1) 
            return 0;
        
        target = (total - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return backtrack(n - 1, target, nums, dp);
    }
};