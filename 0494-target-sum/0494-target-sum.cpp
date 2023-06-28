class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target > sum or (sum - target) % 2 == 1)
            return 0;
        
        target = (sum - target) / 2;
        
        vector<int> dp(target + 1);
        
        dp[0] += 1;
        if(nums[0] <= target)
            dp[nums[0]] += 1;
        for(int ind = 1; ind < n; ++ind) {
            for(int rem = target; rem >= 0; --rem) {
                //Pick Case
                if(rem >= nums[ind]) 
                    dp[rem] += dp[rem - nums[ind]];                
            }
        }
        
        
        return dp[target];
    }
};