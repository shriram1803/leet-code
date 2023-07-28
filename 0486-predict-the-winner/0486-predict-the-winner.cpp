class Solution {
public:
    int f(int front, int back, vector<int>& nums) {
        if(front > back)
            return 0;
        
        int pick_front = nums[front] - f(front + 1, back, nums);
        int pick_back = nums[back] - f(front, back - 1, nums);
        
        return max(pick_front, pick_back);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int res = f(0, n - 1, nums) ;
        
        return res >= 0;
    }
};