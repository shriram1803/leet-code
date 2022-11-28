class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n1 = nums1.size(), n2 = nums2.size();
        for(int num : nums1) {
            res ^= n2 % 2 ? num : 0;
        }
        for(int num : nums2) {
            res ^= n1 % 2 ? num : 0;
        }
        return res;
    }
};