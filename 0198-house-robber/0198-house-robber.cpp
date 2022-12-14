class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev = nums[0], pre = max(nums[1], nums[0]), temp;
        for(int i = 2; i < n; ++i) {
            temp = max(pre, nums[i] + prev);
            prev = pre, pre = temp;
        }
        return max(pre, prev);
    }
};