class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long even_sum = nums[0], odd_sum = nums[0];
        
        if(nums[0] % 2)
            even_sum -= x;
        else
            odd_sum -= x;
        
        for(int i = 1; i < n; ++i) {
            if(nums[i] % 2) {                
                odd_sum = max(odd_sum + nums[i], even_sum - x + nums[i]);
            } else {
                even_sum = max(even_sum + nums[i], odd_sum - x + nums[i]);
            }
        }
        
        return max(even_sum, odd_sum);
    }
};