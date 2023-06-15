class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for(int front = n; front > 0; --front) {
            for(int back = front; back <= n; ++back) {
                for(int k = front; k <= back; ++k) {
                    dp[front][back] = max(dp[front][back], 
                      nums[k] * nums[front - 1] * nums[back + 1] + 
                      dp[front][k - 1] + dp[k + 1][back]
                     );
                }
            } 
        }
        
        return dp[1][n];
    }
};