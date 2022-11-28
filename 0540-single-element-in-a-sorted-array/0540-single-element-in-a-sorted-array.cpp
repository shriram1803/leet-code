class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 1; i < n; i += 2) {
            if(nums[i] != nums[i - 1]) 
                return nums[i - 1];
        }
        return nums[n - 1];
    }
};