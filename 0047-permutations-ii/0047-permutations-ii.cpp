class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> nums, int start, int n) {
        if(start == n - 1) {
            res.push_back(nums);
            return;
        }
        for(int i = start; i < n; ++i){
            if(i != start and nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            solve(nums, start + 1, n);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(nums, 0, n);
        return res;
    }
};