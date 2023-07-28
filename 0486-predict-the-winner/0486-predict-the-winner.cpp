class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n);
        
        for(int front = n - 1; front >= 0; --front) {
            dp[front] = nums[front];
            for(int back = front + 1; back < n; ++back) {
                dp[back] = max(nums[front] - dp[back], nums[back] - dp[back - 1]);                
            }
        }
        
        return dp[n - 1] >= 0;
    }
};