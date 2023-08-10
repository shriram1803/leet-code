class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < nums[right]) {
                if(nums[mid] <= target and target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if(nums[left] <= target and target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        
        return -1;
    }
};