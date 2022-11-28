class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n1 = nums1.size(), n2 = nums2.size();
        for(int num : nums1) {
            for(int i = 0; i < n2; ++i) {
                res ^= num;
            }
        }
        for(int num : nums2) {
            for(int i = 0; i < n1; ++i) {
                res ^= num;
            }
        }  
        return res;
    }
};