class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.emplace_back(nums[0]);
        int len = 1, n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i] > temp.back()) {
                len++;
                temp.emplace_back(nums[i]);
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};