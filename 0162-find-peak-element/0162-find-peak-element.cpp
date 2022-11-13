class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            bool isPeak = true;
            if((i > 0 and nums[i] <= nums[i - 1]) or 
               (i < n - 1 and nums[i] <= nums[i + 1]))
                isPeak = false;
            if(isPeak) return i;
        }
        return -1;
    }
};