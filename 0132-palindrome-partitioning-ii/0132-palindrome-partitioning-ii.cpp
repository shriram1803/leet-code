class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        
        vector<vector<bool>> isPal(n, vector<bool>(n, 0));  
        for(int front = n - 1; front >= 0; --front) {
            for(int back = max(0, front - 1); back < n; ++back) {
                //When front == back - 1 -> the next step back becomes less than front
                if(back <= front) {
                    isPal[front][back] = 1;
                    continue;
                }
                if(s[front] == s[back]) {
                    isPal[front][back] = isPal[front + 1][back - 1];   
                }                    
            }
        }
        
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int k = ind; k < n; ++k) {
                if(isPal[ind][k])
                    dp[ind] = min(dp[ind], 1 + dp[k + 1]);
            }
        }
        
        return dp[0] - 1;
    }
};