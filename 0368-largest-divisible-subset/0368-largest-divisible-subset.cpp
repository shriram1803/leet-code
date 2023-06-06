class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int max_ind = 0, n = nums.size();
        vector<int> dp(n, 1), hash(n);
        
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i) {
            hash[i] = i;
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[max_ind] < dp[i]) {
                max_ind = i;
            }
        }
        
        vector<int> res{nums[max_ind]};
        while(hash[max_ind] != max_ind) {
            max_ind = hash[max_ind];
            res.emplace_back(nums[max_ind]);
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};