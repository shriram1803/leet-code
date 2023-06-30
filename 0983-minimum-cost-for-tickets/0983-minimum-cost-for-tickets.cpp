class Solution {
public:
    vector<int> pass{1, 7, 30};
    int f(int ind, const int n, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(ind == n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int res = 1e9;
        
        for(int i = 0; i < 3; ++i) {
            int k;
            for(k = ind + 1; k < n and (days[ind] + pass[i] - 1 >= days[k]); ++k); 
            res = min(res, costs[i] + f(k, n, days, costs, dp));
        }
        
        return dp[ind] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        vector<int> dp(n, -1);
        
        return f(0, n, days, costs, dp);
    }
};