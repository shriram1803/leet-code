class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0, cont = 1, m = 0; i < nums.size(); ++i) {
            if(i != 0 and nums[i] == nums[i - 1]) {
                cont += 1;
            } else {
                cont = 1;
            }
            if(m < cont) {
                m += 1;
                res.push_back({nums[i]});
            } else {
                res[cont - 1].emplace_back(nums[i]);
            }
        }
        return res;
    }
};