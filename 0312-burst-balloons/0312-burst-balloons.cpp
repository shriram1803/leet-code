class Solution {
public:
    int f(int front, int back, vector<int>& nums, vector<vector<int>>& dp) {
        
        if(front > back) 
            return 0;
        
        if(dp[front][back] != -1)
            return dp[front][back];
        
        int res = -1e9;
        
        for(int k = front; k <= back; ++k) {
            res = max(res, 
                      nums[k] * nums[front - 1] * nums[back + 1] + 
                      f(front, k - 1, nums, dp) + f(k + 1, back, nums, dp)
                     );
        }
        
        return dp[front][back] = res;
    }
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        
        return f(1, n, nums, dp);
    }
};