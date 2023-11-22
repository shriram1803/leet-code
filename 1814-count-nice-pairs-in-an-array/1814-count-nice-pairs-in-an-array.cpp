class Solution {
public:
    const int mod = 1e9 + 7;
    int rev(int num) {
        int res = 0;
        while(num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0;
        
        unordered_map<int, long long> m;
                
        for(int i = 0; i < n; ++i) {
            int rev_num = rev(nums[i]);
            pairs = (m[nums[i] - rev(nums[i])] + pairs) % mod;
            m[nums[i] - rev(nums[i])]++;
        }
        
        
        return pairs;
    }
};