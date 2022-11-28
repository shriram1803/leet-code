class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1;
        int N = nums.size();
        int curr = 0;
        for(int i = 1; i < N; ++i) {
            if((nums[i] & nums[i - 1]) == 0) {
                int temp = curr;
                for(int j = i - 1; j > temp; --j) {
                    if((nums[j - 1] & nums[i]) != 0) {
                        curr = j;
                        break;
                    }
                }
            } else {
                curr = i;
            }
            res = max(i - (curr - 1), res);
        }
        return res;
    }
};