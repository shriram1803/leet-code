class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                return 1;
            
            if(nums[left] == nums[mid] and nums[mid] == nums[right]) {
                left += 1;
                right -= 1;
                continue;
            }
            
            if(nums[left] <= nums[mid]) {
                if(nums[left] <= target and target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {                
                if(nums[mid] < target and target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        
        return 0;
    }
};