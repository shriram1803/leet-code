class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            res[i] += (i * nums[i] - sum);
            sum += nums[i];
        }
        sum = 0;
        for(int i = n - 1; i >= 0; --i) {
            res[i] += (sum - (n - i - 1) * nums[i]);
            sum += nums[i];
        }
        return res;
    }
};