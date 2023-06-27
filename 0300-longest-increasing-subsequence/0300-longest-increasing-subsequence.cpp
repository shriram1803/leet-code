class Solution {
public:
    int f(int ind, int prev, const int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == n)
            return 0;
        
        if(dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        
        int not_pick = f(ind + 1, prev, n, nums, dp);
        int pick = -1e9;
        if(prev == -1 or nums[ind] > nums[prev])
            pick = 1 + f(ind + 1, ind, n, nums, dp);
        
        return dp[ind][prev + 1] = max(not_pick, pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return f(0, -1, n, nums, dp);
    }
};