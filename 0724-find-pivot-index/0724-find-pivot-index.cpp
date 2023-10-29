class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        int ps = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(ps == sm - nums[i] - ps)
                return i;
            ps += nums[i];
        }
        return -1;
    }
};