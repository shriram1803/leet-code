class Solution {
public:
    int backtrack(int curr, int ind, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0) {  
            return curr == nums[ind];
        }
        if(curr < 0)
            return 0;
        
        if(dp[ind][curr] != -1) 
            return dp[ind][curr];
        
        int pick = backtrack(curr - nums[ind], ind - 1, nums, dp);
        int not_pick = backtrack(curr, ind - 1, nums, dp);
        
        return dp[ind][curr] = pick | not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s % 2 == 1) 
            return 0;
        int target = s / 2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return backtrack(target, n - 1, nums, dp);
    }
};