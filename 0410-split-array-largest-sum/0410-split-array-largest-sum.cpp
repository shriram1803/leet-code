class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid) {
        int curr = 0;
        for(int& num : nums) {
            if(curr + num > mid)
                curr = num, k -= 1;
            else
                curr += num;
        }
        //Due to the constraint k <= n: as long as k >= 1 we return 1 
        //(there will be enough elements remaining to split)
        return k >= 1;
    } 
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(canSplit(nums, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};