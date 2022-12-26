class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        for(int reach = 0; ind < n and ind <= reach; ++ind) {
            reach = max(reach, ind + nums[ind]);
        }
        return ind >= n;
    }
};