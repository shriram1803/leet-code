class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); ++i) m[nums1[i]] = i, nums1[i] = -1;
        for(int i = 0; i < nums2.size(); ++i) {
            while(s.size() and nums2[s.back()] < nums2[i]) {
                if(m.find(nums2[s.back()]) != m.end()) {
                    nums1[m[nums2[s.back()]]] = nums2[i];
                }
                s.pop_back();
            }
            s.emplace_back(i);
        }
        return nums1;
    }
};