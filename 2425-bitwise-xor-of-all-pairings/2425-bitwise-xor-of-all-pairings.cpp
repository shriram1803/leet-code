class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n1 = nums1.size(), n2 = nums2.size();
        if(n2 % 2 == 1)
            for(int num : nums1)
                res ^= num;
        if(n1 % 2 == 1)
            for(int num : nums2)
                res ^= num;
        return res;
    }
};