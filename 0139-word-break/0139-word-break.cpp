class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        vector<int> dp(n + 1, 0);
        
        dp[n] = 1;
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(auto& word : wordDict) {
                if(s.substr(ind, word.size()) == word)
                    if(dp[ind + word.size()])
                        dp[ind] = 1;
            }
        }
        
        return dp[0];
    }
};