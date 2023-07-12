class Solution {
public:
    int f(vector<int>& nums, int rem, vector<int>& dp) {
        if(rem == 0)
            return 1;
        
        if(dp[rem] != -1)
            return dp[rem];
        
        int res = 0;
        for(auto& num : nums) 
            if(num <= rem)
                res += f(nums, rem - num, dp);
        
        
        return dp[rem] = res;
    } 
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return f(nums, target, dp);
    }
};