class Solution {
public:
    int backtrack(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == n) 
            return 0;
        
        if(dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        
        //Not pick case
        int res = backtrack(ind + 1, prev_ind, n, nums, dp);
        
        //Pick case
        if(prev_ind == -1 or nums[ind] > nums[prev_ind])
            res = max(res, 1 + backtrack(ind + 1, ind, n, nums, dp));
        
        return dp[ind][prev_ind + 1] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return backtrack(0, -1, n, nums, dp);
    }
};