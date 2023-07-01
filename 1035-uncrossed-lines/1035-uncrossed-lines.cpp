class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<int> prev(n + 1), curr(n + 1);
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(nums1[i - 1] == nums2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        } 
        
        return prev[n];
    }
};