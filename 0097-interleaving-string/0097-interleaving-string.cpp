class Solution {
public:
    bool f(int i, int j, int ind, string& a, string& b, string& targ, vector<vector<vector<int>>>& dp) {
        
        if(i == 0 and j == 0) 
            return 1;
        
        if(i == 0) 
            return b.substr(0, j) == targ.substr(0, j);
        
        if(j == 0) 
            return a.substr(0, i) == targ.substr(0, i);
            
        
        if(dp[i][j][ind] != -1)
            return dp[i][j][ind];
        
        if(targ[ind] == a[i - 1] and targ[ind] == b[j - 1]) 
            return dp[i][j][ind] = f(i - 1, j, ind - 1, a, b, targ, dp) | f(i, j - 1, ind - 1, a, b, targ, dp);
        
        if(targ[ind] == a[i - 1])
            return dp[i][j][ind] = f(i - 1, j, ind - 1, a, b, targ, dp);
        
        if(targ[ind] == b[j - 1])
            return dp[i][j][ind] = f(i, j - 1, ind - 1, a, b, targ, dp);
        
        return dp[i][j][ind] = 0;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), o = s3.size();
        if(o != m + n) return false;
        vector<vector<vector<int>>> dp(m + 1, 
                                      vector<vector<int>>(n + 1,
                                                        vector<int>(o + 1, -1)));
        return f(m, n, o - 1, s1, s2, s3, dp);
    }
};