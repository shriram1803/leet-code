class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        int lft = INT_MAX;
        int rht = INT_MIN;
        for(int i = 0; i < n; ++i) {
            left[i] = lft;
            lft = min(lft, nums[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            right[i] = rht;
            rht = max(rht, nums[i]);
        }
        for(int i = 0; i < n; ++i) {
            if(left[i] < nums[i] and nums[i] < right[i])
                return true;
        }
        return false;
    }
};