class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroes = 0;
        int res = 0;
        
        for(int i = 0, j = 0; i < n; ++i) {
            if(nums[i] == 0) {
                ++zeroes;
                while(j <= i and zeroes > k) {
                    if(nums[j] == 0) {
                        --zeroes;
                    } 
                    ++j;
                }
            }
            res = max(res, i - j + 1);
        }
        
        return res;
    }
    int longestSubarray(vector<int>& nums) {
        return longestOnes(nums, 1) - 1;
    }
};