class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int ind) {
        if(ind == 0) {
            res.emplace_back(nums);
            return;
        }
        
        for(int i = ind; i >= 0; --i) {
            swap(nums[i], nums[ind]);
            backtrack(res, nums, ind - 1);
            swap(nums[i], nums[ind]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, nums.size() - 1);
        return res;
    }
};