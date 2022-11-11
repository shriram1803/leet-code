class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 1, b = 1;
        while(b < nums.size()){
            if(nums[a - 1] != nums[b]) {
                nums[a++] = nums[b];
            }
            b++;
        }
        return a;
    }
};