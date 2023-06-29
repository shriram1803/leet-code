class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(int ind = 1; ind <= N; ++ind) {
            for(int i = m; i >= 0; --i) {
                for(int j = n; j >= 0; --j) {
                    
                    int zeroes = count(strs[ind - 1].begin(), strs[ind - 1].end(), '0');

                    int pick = -1e9;
                    if(i >= zeroes and j >= (strs[ind - 1].size() - zeroes))
                        pick = 1 + dp[i - zeroes][j - (strs[ind - 1].size() - zeroes)];

                    dp[i][j] = max(dp[i][j], pick);
                }
            }
        }
        
        return dp[m][n];
    }
};