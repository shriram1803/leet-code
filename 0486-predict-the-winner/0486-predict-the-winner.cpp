class Solution {
public:
    int f(int front, int back, vector<int>& nums, vector<vector<int>>& dp) {
        if(front > back)
            return 0;
        
        if(dp[front][back] != -1)
            return dp[front][back];
        
        int pick_front = nums[front] - f(front + 1, back, nums, dp);
        int pick_back = nums[back] - f(front, back - 1, nums, dp);
        
        return dp[front][back] = max(pick_front, pick_back);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return f(0, n - 1, nums, dp) >= 0;
    }
};