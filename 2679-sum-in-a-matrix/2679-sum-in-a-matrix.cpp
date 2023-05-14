class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto& row : nums) {
            sort(row.begin(), row.end());
        }
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < nums[0].size(); ++i) {
            for(int j = 1; j < n; ++j) {
                nums[j][i] = max(nums[j - 1][i], nums[j][i]);
            }
            res += nums[n - 1][i];
        }
        return res;
    }
};