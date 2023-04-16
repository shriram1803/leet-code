class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        long long maxx = nums[0];
        res[0] = nums[0] * 2;
        for(int i = 1; i < n; ++i) {
            maxx = max(maxx, (long long)nums[i]);
            res[i] = res[i - 1] + maxx + (long long)nums[i];
        }
        return res;
    }
};