class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i = 0, j = 0; i < n; ++i) {
            res.emplace_back(nums[i]);
            res.emplace_back(nums[i + n]);
        }
        return res;
    }
};