class Solution {
public:
    bool f(int i, int j, int m, int n, int ind, string& a, string& b, string& targ, vector<vector<vector<int>>>& dp) {
        if(i == m and j == n) 
            return 1;
        
        if(dp[i][j][ind] != -1)
            return dp[i][j][ind];

        if(i == m) {
            if(b[j++] == targ[ind++])
                return dp[i][j][ind] = f(i, j, m, n, ind, a, b, targ, dp);
            return dp[i][j][ind] = 0;
        }
        
        if(j == n) {
            if(a[i++] == targ[ind++])
                return dp[i][j][ind] = f(i, j, m, n, ind, a, b, targ, dp);
            return 0;
        }
        
        if(a[i] == b[j] and b[j] == targ[ind]) 
            return dp[i][j][ind] = f(i + 1, j, m, n, ind + 1, a, b, targ, dp) | f(i, j + 1, m, n, ind + 1, a, b, targ, dp);
        
        if(a[i] == targ[ind])
            return dp[i][j][ind] = f(i + 1, j, m, n, ind + 1, a, b, targ, dp);
        
        if(b[j] == targ[ind]) 
            return dp[i][j][ind] = f(i, j + 1, m, n, ind + 1, a, b, targ, dp);
        
        return dp[i][j][ind] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        if(o != m + n) return false;
        vector<vector<vector<int>>> dp(m + 1, 
                                      vector<vector<int>>(n + 1,
                                                        vector<int>(o + 1, -1)));
        return f(0, 0, m, n, 0, s1, s2, s3, dp);
    }
};