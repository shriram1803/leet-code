class Solution {
public:
    int solver(vector<int>& nums, int start, int end, const int n) {
        int prev = 0, pre = 0;
        for(int i = start; i <= end; ++i) {
            int tmp = max(pre, nums[i] + prev);
            prev = pre, pre = tmp;
        }
        return pre;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solver(nums, 0, n - 2, n), solver(nums, 1, n - 1, n));
    }
};