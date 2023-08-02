class Solution {
public:
    void backtrack(int ind, const int n, vector<int>& nums, vector<vector<int>>& res) {
        if(ind == n) {
            res.emplace_back(nums);
            return;
        }
        
        for(int i = ind; i < n; ++i) {
            swap(nums[i], nums[ind]);
            backtrack(ind + 1, n, nums, res);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        backtrack(0, nums.size(), nums, res);
        
        return res;
    }
};