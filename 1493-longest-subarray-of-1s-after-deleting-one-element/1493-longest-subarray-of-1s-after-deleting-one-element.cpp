class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int prev_zero = -1;
        int cur_zero = -1;
        int res = 0;
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                prev_zero = cur_zero;
                cur_zero = i;
            }
            res = max(res, i - prev_zero - 1);
        }
        
        return res;
    }
};