class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        
        vector<long long> dp(n + 1);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            
            dp[ind] = max(dp[ind + 1], (long long)q[ind][0]); //
            if(ind + q[ind][1] < n)
                dp[ind] = max(dp[ind], q[ind][0] + dp[ind + q[ind][1] + 1]);
            
        }
        
        return dp[0];
    }
};