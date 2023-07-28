class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prev(n);
        vector<int> curr(n);
        
        for(int front = n - 1; front >= 0; --front) {
            curr[front] = nums[front];
            for(int back = front + 1; back < n; ++back) {
                        
                curr[back] = max(nums[front] - prev[back], nums[back] - curr[back - 1]);
                
            }
            prev = curr;
        }
        
        return prev[n - 1] >= 0;
    }
};