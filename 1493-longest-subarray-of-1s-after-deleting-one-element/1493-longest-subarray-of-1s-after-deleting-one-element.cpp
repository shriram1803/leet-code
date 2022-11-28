class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0, current = 0, n = nums.size();
        int pass = 1, ind = -1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 1) current++;
            else {
                if(pass) {
                    ind = i;
                    pass--;
                } else {
                    current = i - (ind + 1);
                    ind = i;
                }
            }
            longest = max(longest, current);
        }
        if(pass == 1) return longest - 1;
        return longest;
    }
};