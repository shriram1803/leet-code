class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int ind, vector<int> curr, const int n) {
        if(ind == n) {
            res.push_back(curr);
            return;
        }
        solve(nums, ind + 1, curr, n);
        curr.push_back(nums[ind]);
        solve(nums, ind + 1, curr, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(nums, 0, {}, n);
        return res;
    }
};