class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = 0;
        
        while(left < right) {            
            if(nums[left] + nums[right] < k) {
                ++left;
            } else if(nums[left] + nums[right] > k) {
                --right;
            } else {
                ++res;
                ++left;
                --right;
            }
        }
        
        return res;
    }
};