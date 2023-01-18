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
        long tot = accumulate(nums.begin(), nums.end(), (long)0);
        long pos = kadane(nums), neg = negativekadane(nums);
        long val = tot - neg;
        if(val == 0) val = INT_MIN;
        long res = max(pos, val);
        return res;
    }
};