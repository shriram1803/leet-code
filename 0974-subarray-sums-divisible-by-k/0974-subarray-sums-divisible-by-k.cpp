class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> mod(k, 0);
        int sum = 0;
        for(int num : nums) {
            sum += num;
            ++mod[((sum % k) + k) % k];
        }
        int res = 0;
        for(int i = 0; i < k; ++i) {
            res += mod[i] * (mod[i] - 1) / 2;
        }
        return res + mod[0];
        
    }
};