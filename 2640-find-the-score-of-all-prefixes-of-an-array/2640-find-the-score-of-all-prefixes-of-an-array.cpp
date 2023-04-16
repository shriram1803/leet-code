class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        int maxx = nums[0];
        res[0] = nums[0] * 2;
        for(int i = 1; i < n; ++i) {
            maxx = max(maxx, nums[i]);
            res[i] = res[i - 1] + ((long long)nums[i] + (long long)maxx);
        }
        return res;
    }
};