class Solution {
public:
    long long f(int ind, const int n, vector<vector<int>>& q, vector<long long>& dp) {
        if(ind == n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        long long not_pick = f(ind + 1, n, q, dp);
        
        long long pick = q[ind][0];
        if(ind + q[ind][1] < n)
            pick += f(ind + q[ind][1] + 1, n, q, dp);
        
        
        return dp[ind] = max(not_pick, pick);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        
        vector<long long> dp(n, -1);
        
        return f(0, n, q, dp);
    }
};