class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target > sum or (sum - target) % 2 == 1)
            return 0;
        
        target = (sum - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1));
        
        dp[0][0] += 1;
        if(nums[0] <= target)
            dp[0][nums[0]] += 1;
        for(int ind = 1; ind < n; ++ind) {
            for(int rem = 0; rem <= target; ++rem) {
                
                //Not pick case
                int res = dp[ind - 1][rem];

                //Pick Case
                if(rem >= nums[ind]) 
                    res += dp[ind - 1][rem - nums[ind]];

                dp[ind][rem] = res;
                
            }
        }
        
        
        return dp[n - 1][target];
    }
};