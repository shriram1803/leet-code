class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        
        for(int ind = 1; ind <= N; ++ind) {
            for(int i = 0; i <= m; ++i) {
                for(int j = 0; j <= n; ++j) {
                    
                    int not_pick = dp[ind - 1][i][j];
                    int zeroes = 0;
                    for(int k = 0; k < strs[ind - 1].size(); ++k) {
                        if(strs[ind - 1][k] == '0')
                            zeroes += 1;
                    }

                    int pick = -1e9;
                    if(i >= zeroes and j >= (strs[ind - 1].size() - zeroes))
                        pick = 1 + dp[ind - 1][i - zeroes][j - (strs[ind - 1].size() - zeroes)];

                    dp[ind][i][j] = max(not_pick, pick);
                }
            }
        }
        
        return dp[N][m][n];
    }
};