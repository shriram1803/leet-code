class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target > sum or (sum - target) % 2 == 1)
            return 0;
        
        target = (sum - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1));
        vector<int> prev(target + 1), curr(target + 1);
        
        prev[0] += 1;
        if(nums[0] <= target)
            prev[nums[0]] += 1;
        for(int ind = 1; ind < n; ++ind) {
            for(int rem = 0; rem <= target; ++rem) {
                
                //Not pick case
                int res = prev[rem];

                //Pick Case
                if(rem >= nums[ind]) 
                    res += prev[rem - nums[ind]];

                curr[rem] = res;
                
            }
            
            prev = curr;
        }
        
        
        return prev[target];
    }
};