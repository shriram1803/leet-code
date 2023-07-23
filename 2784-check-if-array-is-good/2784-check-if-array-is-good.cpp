class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 1 or nums[0] != 1)
            return 0;
        for(int i = 1; i < n - 1; ++i) {
            if(nums[i] == nums[i - 1] or nums[i] != (i + 1))
                return 0;
        }
        return nums[n - 1] == nums[n - 2];
    }
};