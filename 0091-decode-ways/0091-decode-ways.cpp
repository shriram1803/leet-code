class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(2);
        dp[0] = 1;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            int ans = 0;
            for(int k = 1; ind + k <= n and k <= 2; ++k) {
                int curr = stoi(s.substr(ind, k));
                if(s[ind] == '0')
                    continue;
                if(0 < curr and curr <= 26) 
                    ans += dp[k - 1];
            }
            dp[1] = dp[0], dp[0] = ans;
        }
        
        return dp[0];
    }
};