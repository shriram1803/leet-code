class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int suf_sum = accumulate(nums.begin(), nums.end(), 0);
        int pref_sum = 0;
        vector<int> res(n);
        
        for(int i = 0; i < n; ++i) {
            suf_sum -= nums[i];
            res[i] = (suf_sum - (n - i - 1) * nums[i]) + (i * nums[i] - pref_sum);
            pref_sum += nums[i];
        }
        
        return res;
    }
};