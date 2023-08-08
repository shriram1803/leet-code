class Solution {
public:
    int bs(int left, int right, vector<int>& nums, int targ) {
        if(left > right)
            return -1;
        
        int mid = left + (right - left) / 2;
        
        if(nums[mid] == targ)
            return mid;
        
        if(nums[left] < targ and targ < nums[right]) {
            if(nums[mid] < targ)
                return bs(mid + 1, right, nums, targ);
            else
                return bs(left, mid - 1, nums, targ);
        }
        
        return max(bs(left, mid - 1, nums, targ), bs(mid + 1, right, nums, targ));        
    }
    int search(vector<int>& nums, int target) {
        
        return bs(0, nums.size() - 1, nums, target);
    }
};