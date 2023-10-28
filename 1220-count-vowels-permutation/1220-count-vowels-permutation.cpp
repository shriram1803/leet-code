class Solution {
public:
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    const int mod = 1e9 + 7;
    int f(int n, int prev, vector<vector<int>>& dp) {
        if(n <= 1)
            return n;
        
        if(dp[n][prev] != -1)
            return dp[n][prev];
        
        long long local = 0;
        
        if(vowels[prev] == 'a') {
            local = (local + f(n - 1, 1, dp)) % mod;
        } else if(vowels[prev] == 'e') {
            local = (local + f(n - 1, 0, dp) + f(n - 1, 2, dp)) % mod;
        } else if(vowels[prev] == 'i') {
            for(int i = 0; i < 5; ++i)
                if(vowels[i] != 'i')
                   local = (local + f(n - 1, i, dp)) % mod;
        } else if(vowels[prev] == 'o') {
            local = (local + f(n - 1, 2, dp) + f(n - 1, 4, dp)) % mod;
        } else {
            local = (local + f(n - 1, 0, dp)) % mod;
        }
                   
        return dp[n][prev] = local % mod;
    }
    int countVowelPermutation(int n) {
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        for(int i = 0; i < 5; ++i)
            res = ((long long)res + f(n, i, dp)) % mod;
        return res;
    }
};