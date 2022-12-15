class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cumulative = 0, res = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            cumulative += nums[i];
            res = max(res, cumulative);
            if(cumulative < 0) cumulative = 0;
        }
        return res;
    }
};