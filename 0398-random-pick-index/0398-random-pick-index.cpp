class Solution {
public:
    unordered_map<int, vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            m[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        int n = m[target].size();
        int ind = rand() % n;
        return m[target][ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */