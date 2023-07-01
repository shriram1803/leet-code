class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<int> dp(n + 1);
        
        //Space Optimization PRO MAXX Approach
        for(int i = 1; i <= m; ++i) {
            int prev = 0;
            for(int j = 1; j <= n; ++j) {
                int tmp = dp[j];
                if(nums1[i - 1] == nums2[j - 1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = tmp;
            }
        } 
        
        return dp[n];
    }
};