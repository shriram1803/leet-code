class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int ind, vector<int>& curr, const int n) {
        if(ind == n) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(nums, ind + 1, curr, n);
        curr.pop_back();
        while(ind < n - 1 and nums[ind] == nums[ind + 1]) ind++;
        solve(nums, ind + 1, curr, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(nums, 0, v, n);
        return res;
    }
};