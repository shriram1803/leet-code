class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, 1), counter(n, 1);
        int maxi = 1;
        
        for(int ind = 0; ind < n; ++ind) {
            for(int prev_ind = 0; prev_ind < ind; ++prev_ind) {
                if(nums[ind] > nums[prev_ind]) {
                    if(1 + dp[prev_ind] > dp[ind]) {
                        dp[ind] = 1 + dp[prev_ind];
                        counter[ind] = counter[prev_ind];
                    } else if(1 + dp[prev_ind] == dp[ind]) {
                        counter[ind] += counter[prev_ind];
                    }
                } 
            }
            maxi = max(maxi, dp[ind]);
        }
        
        int res = 0;
        
        for(int i = 0; i < n; ++i) {
            if(dp[i] == maxi)
                res += counter[i];
        }
        
        return res;
    }
};