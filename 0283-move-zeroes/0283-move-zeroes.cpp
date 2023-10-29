class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, curr = 0; i < n; ++i) {
            while(i < n and nums[i] == 0)
                ++i;
            if(i < n)
                swap(nums[curr++], nums[i]);
        }
    }
};