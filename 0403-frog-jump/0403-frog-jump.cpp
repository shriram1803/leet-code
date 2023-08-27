class Solution {
public:
    bool f(int ind, int prev, int n, vector<int>& stones, vector<vector<int>>& dp) {
        if(ind == n - 1)
            return 1;
        
        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int prev_jump = stones[ind] - stones[prev];
        
        int max_reach = stones[ind] + prev_jump + 1; 
        
        for(int j = ind + 1; j < n and stones[j] <= max_reach; ++j) {
            
            for(int k = prev_jump - 1; k <= prev_jump + 1; ++k) {
                if(stones[j] - stones[ind] == k and f(j, ind, n, stones, dp))
                    return dp[ind][prev] = 1;
            }
            
        }
        
        return dp[ind][prev] = 0; 
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        if(stones[1] != 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return f(1, 0, n, stones, dp);
    }
};