class Solution {
public:
    vector<int> pass{1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int i = 0; i < 3; ++i) {
                int k = upper_bound(days.begin(), days.end(), days[ind] + pass[i] - 1) - days.begin();
                dp[ind] = min(dp[ind], costs[i] + dp[k]);
            }
        }
        
        return dp[0];
    }
};