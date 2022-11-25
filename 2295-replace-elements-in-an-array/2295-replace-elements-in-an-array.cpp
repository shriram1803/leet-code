class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> ind;
        for(int i = 0; i < nums.size(); ++i) {
            ind[nums[i]] = i;
        }
        for(auto& operation : operations) {
            int curr = ind[operation[0]];
            nums[curr] = operation[1];
            ind[operation[1]] = curr;
        }
        return nums;
    }
};