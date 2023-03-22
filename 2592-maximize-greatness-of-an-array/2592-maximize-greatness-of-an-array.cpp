class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int& num : nums) {
            if(num > nums[res]) {
                res += 1;
            }
        } 
        return res;
    }
};