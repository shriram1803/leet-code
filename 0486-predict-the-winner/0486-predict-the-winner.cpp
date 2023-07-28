class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i) 
            dp[i][i] = nums[i];
        
        for(int front = n - 1; front >= 0; --front) {
            for(int back = front + 1; back < n; ++back) {
                
                int pick_front = nums[front] - dp[front + 1][back];
                int pick_back = nums[back] - dp[front][back - 1];
        
                dp[front][back] = max(pick_front, pick_back);
                
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
};