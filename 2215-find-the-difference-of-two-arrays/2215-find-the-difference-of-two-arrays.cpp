class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for(auto num : s1) {
            if(s2.count(num))
                continue;
            res[0].emplace_back(num);
        }
        for(auto num : s2) {
            if(s1.count(num))
                continue;
            res[1].emplace_back(num);
        }
        return res;
    }
};