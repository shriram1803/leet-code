class Solution {
public: 
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i < 0 and j < 0)
            return 0;
        if(i < 0) {
            int s = 0;
            while(j >= 0)
                s += s2[j--];
            return s;
        }
        if(j < 0) {
            int s = 0;
            while(i >= 0)
                s += s1[i--];
            return s;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        
        return dp[i][j] = min(s1[i] + f(i - 1, j, s1, s2, dp), s2[j] + f(i, j - 1, s1, s2, dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return f(m - 1, n - 1, s1, s2, dp);
    }
};