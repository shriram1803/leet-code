class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int& num : nums) res ^= num;
        return res;
    }
};