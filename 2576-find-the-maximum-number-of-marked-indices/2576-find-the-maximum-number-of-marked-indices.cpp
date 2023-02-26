class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = nums.size() / 2 - 1, j = nums.size() - 1; i >= 0; --i) {   
            if(nums[i] * 2 <= nums[j]) {
                --j;
                res += 2;
            }
        }
        return res;
    }
};