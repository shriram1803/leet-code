class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, tot = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < n; ++i) {
            tot -= nums[i];
            int val = (i * nums[i] - sum) + (tot - (n - i - 1) * nums[i]);
            sum += nums[i];
            nums[i] = val;
        }
        return nums;
    }
};