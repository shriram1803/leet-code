class Solution {
public:
    bool f(int ind, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0)
            return rem == nums[0];
        
        if(dp[ind][rem] != -1)
            return dp[ind][rem];
        
        int not_pick = f(ind - 1, rem, nums, dp);
        int pick = 0;
        if(rem >= nums[ind]) 
            pick = f(ind - 1, rem - nums[ind], nums, dp);
        
        return dp[ind][rem] = not_pick | pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        
        return f(n - 1, sum / 2, nums, dp);
    }
};