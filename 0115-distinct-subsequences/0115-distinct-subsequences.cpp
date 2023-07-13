class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n + 1);
        
        for(int i = 1; i <= m; ++i) {
            dp[0] = 1;
            for(int j = n; j >= 1; --j) {
                if(s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
            }
        }
        
        return dp[n];
    }
};