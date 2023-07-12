class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int rem = 1; rem <= target; ++rem) {
            for(auto& num : nums) 
                if(num <= rem)
                    dp[rem] += dp[rem - num];
        }
        
        return dp[target];
    }
};