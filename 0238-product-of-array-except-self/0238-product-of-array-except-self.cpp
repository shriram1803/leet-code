class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        left[0] = nums[0];
        for(int i = 1; i < n; ++i) left[i] = nums[i] * left[i - 1];
        int right = 1;
        for(int i = n - 1; i >= 1; --i) {
            int save = nums[i];
            nums[i] = left[i - 1] * right;
            right *= save;
        }
        nums[0] = right;
        return nums;
    }
};