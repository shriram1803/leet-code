class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, reach = 0, count = 0;
        for(int i = 0; i < n; ++i) {
            if(reach >= n - 1) break;
            curr = max(curr, i + nums[i]);
            if(reach <= i) {
                reach = curr;
                ++count;
            }
        }
        return count;
    }
};