class Solution {
public:
    int f(int ind, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0)
            return (rem == 0) + (rem == nums[0]);
        
        if(dp[ind][rem] != -1)
            return dp[ind][rem];
        
        //Not pick case
        int res = f(ind - 1, rem, nums, dp);
        
        //Pick Case
        if(rem >= nums[ind]) 
            res += f(ind - 1, rem - nums[ind], nums, dp);
        
        return dp[ind][rem] = res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target > sum or (sum - target) % 2 == 1)
            return 0;
        
        target = (sum - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return f(n - 1, target, nums, dp);
    }
};