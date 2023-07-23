class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int& num : nums) 
            if(num < 0)
                num = 0;
        
        for(int& num : nums) {
            if(num == 0 or abs(num) > n or nums[abs(num) - 1] < 0)
                continue;
            if(nums[abs(num) - 1] == 0) {
                nums[abs(num) - 1] = -(n + 1);
            } else {
                nums[abs(num) - 1] = -nums[abs(num) - 1]; 
            }             
        } 
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] >= 0)
                return i + 1;
        }
        
        return n + 1;
    }
};