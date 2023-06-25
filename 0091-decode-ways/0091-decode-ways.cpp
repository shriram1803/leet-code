class Solution {
public:
    int f(int ind, const int n, string& s, vector<int>& dp) {
        if(ind == n)
            return 1;
        
        if(s[ind] == '0') 
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = 0;
        for(int k = 1; ind + k <= n and k <= 2; ++k) {
            int curr = stoi(s.substr(ind, k));
            if(0 < curr and curr <= 26) 
                ans += f(ind + k, n, s, dp);
        }
        
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return f(0, n, s, dp);
    }
};