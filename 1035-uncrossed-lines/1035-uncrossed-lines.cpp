class Solution {
public:
    int f(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i == 0 or j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i - 1] == nums2[j - 1])
            return 1 + f(i - 1, j - 1, nums1, nums2, dp);
        
        return dp[i][j] = max(
            f(i - 1, j, nums1, nums2, dp),
            f(i, j - 1, nums1, nums2, dp)
        );
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return f(m, n, nums1, nums2, dp);
    }
};