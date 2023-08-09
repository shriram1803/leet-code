class Solution {
public:
    bool isGood(vector<int>& nums, int m, int p) {
        for(int i = 1; i < nums.size() and p > 0; ++i) {
            if(nums[i] - nums[i - 1] <= m)
                p -= 1, i += 1;
        }
        return p == 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums[0];
        int mid;
        
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(isGood(nums, mid, p)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        
        return left;
    }
};