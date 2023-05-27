class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s % 2 == 1) 
            return 0;
        int target = s / 2;
        vector<vector<int>> dp(N, vector<int>(target + 1, 0));
        if(target >= nums[0])
            dp[0][nums[0]] = 1;
        
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j <= target; ++j) {
                int not_pick = dp[i - 1][j];
                int pick = 0;
                if(j >= nums[i])
                    pick = dp[i - 1][j - nums[i]];
                dp[i][j] = pick | not_pick;
            }
        }
        
        return dp[N - 1][target];
    }
};