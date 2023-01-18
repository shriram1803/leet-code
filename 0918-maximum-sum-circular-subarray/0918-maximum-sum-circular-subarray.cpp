class Solution {
public:
    int kadane(vector<int>& nums) {
        int s = 0, res = INT_MIN;
        for(int num : nums) {
            s += num;
            res = max(res, s);
            if(s < 0) s = 0;
        }
        return res;
    }
    int negativekadane(vector<int>& nums) {
        int s = 0, res = INT_MAX;
        for(int num : nums) {
            s += num;
            res = min(res, s);
            if(s > 0) s = 0;
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int pos = kadane(nums), neg = negativekadane(nums);
        int val = tot - neg;
        if(val == 0) return pos;
        return max(pos, val);
    }
};