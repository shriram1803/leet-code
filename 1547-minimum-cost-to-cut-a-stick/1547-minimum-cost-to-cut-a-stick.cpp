class Solution {
public:
    int f(int front, int back, vector<int>& cuts, vector<vector<int>>& dp) {
        
        if(front > back)
            return 0;
        
        if(dp[front][back] != -1)
            return dp[front][back];
        
        int res = 1e9;
        
        for(int k = front; k <= back; ++k) {
            res = min(res, 
                      cuts[back + 1] - 
                      cuts[front - 1] + 
                      f(front, k - 1, cuts, dp) + 
                      f(k + 1, back, cuts, dp)
                     );
        }
        
        return dp[front][back] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());
        
        int N = cuts.size();
        
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        
        return f(1, N - 2, cuts, dp);
    }
};