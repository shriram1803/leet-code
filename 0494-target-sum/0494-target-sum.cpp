class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        
        if(total < target or (total - target) % 2 == 1) 
            return 0;
        
        target = (total - target) / 2;
        
        vector<int> dp(target + 1, 0);
        
        dp[0] = 1;
        if(target >= nums[0])
            dp[nums[0]] += 1;
        
        for(int ind = 1; ind < n; ++ind) {
            for(int targ = target; targ >= 0; --targ) {
                int not_pick = dp[targ];
                int pick = 0;
                if(targ >= nums[ind])
                    pick += dp[targ - nums[ind]];
                dp[targ] = pick + not_pick;
            }
        }
        
        return dp[target];
    }
};