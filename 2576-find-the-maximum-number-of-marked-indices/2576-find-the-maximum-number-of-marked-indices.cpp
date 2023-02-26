class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for(int i = n / 2 - 1, j = n - 1; i >= 0; --i) {   
            if(nums[i] * 2 <= nums[j]) {
                --j;
                res += 1;
            }
        }
        return res * 2;
    }
};