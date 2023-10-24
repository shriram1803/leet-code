class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k, right = k;
        int minn = nums[k];
        int res = nums[k] * 1;
        
        /*
        Approach: GREEDY
        STart from the middle and expand towards each side having greater element
        to try our best to avoid smaller elements
        */
        
        while(left > 0 or right < n - 1) {
            if(left > 0 and right < n - 1) {
                if(nums[left - 1] < nums[right + 1]) {
                    right += 1;
                    minn = min(minn, nums[right]);
                } else if(nums[left - 1] == nums[right + 1]) {
                    right += 1;
                    left -= 1;
                    minn = min(minn, nums[right]);    
                    minn = min(minn, nums[left]);                
                } else {
                    left -= 1;
                    minn = min(minn, nums[left]);
                }
            } else if(left > 0) {                
                left -= 1;
                minn = min(minn, nums[left]);
            } else {
                right += 1;
                minn = min(minn, nums[right]);
            }
            res = max(res, minn * (1 + (right - left)));
        }
        
        return res;
    }
};