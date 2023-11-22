class Solution {
public:
    const int mod = 1e9 + 7;
    void rev(int num, long long &res) {
        res = 0;
        while(num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0;
        long long rev_num;
        
        unordered_map<int, long long> m;
                
        for(int i = 0; i < n; ++i) {
            rev(nums[i], rev_num);
            pairs = (m[nums[i] - rev_num] + pairs) % mod;
            m[nums[i] - rev_num]++;
        }
        
        
        return pairs;
    }
};