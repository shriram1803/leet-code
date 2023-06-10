class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());
        
        int N = cuts.size();
        
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1e9));
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i][j] = 0;
            }
        }
        
        for(int front = N - 2; front > 0; --front) {
            for(int back = front; back < N - 1; ++back) {
                for(int k = front; k <= back; ++k) {
                    dp[front][back] = min(dp[front][back], 
                                          cuts[back + 1] - cuts[front - 1] 
                                          + dp[front][k - 1] + dp[k + 1][back]);
                }
            }
        }
        
        return dp[1][N - 2];
    }
};