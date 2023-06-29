class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(int ind = 1; ind <= N; ++ind) {
            for(int i = m; i >= 0; --i) {
                for(int j = n; j >= 0; --j) {
                    
                    int zeroes = 0;
                    for(int k = 0; k < strs[ind - 1].size(); ++k) {
                        if(strs[ind - 1][k] == '0')
                            zeroes += 1;
                    }

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